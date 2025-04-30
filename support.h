/*
 * MIT License
 * 
 * Copyright (c) 2025 effeligo
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#define MAX_ESSID_LENGTH 32
#define CHANNEL_NUMBER 13

typedef struct _node{
  u_char station[6];
  struct timeval tv;
  int status; 
  struct _node *next;  
} node;

typedef node *list;

typedef struct _info{
  uint16_t channel;
  int8_t signal;
  list stations;
} info;

typedef struct _ap_node{
  char essid[MAX_ESSID_LENGTH];
  u_char bssid[6];
  int chsist_index;
  info chsist[CHANNEL_NUMBER];
  struct timeval tv;
  struct _ap_node *next;
} ap_node;

typedef ap_node *ap_list;

ap_list new_ap_list();
void update_ap(ap_list *apl, char *essid, u_char *bssid, uint16_t channel,
	       int8_t signal, const struct pcap_pkthdr h);
void update_stations(ap_list *apl, u_char *bssid, u_char *station, uint16_t channel,
		     const struct pcap_pkthdr h);
void print_beacon(const struct pcap_pkthdr h, char *essid, u_char *bssid,
		  uint16_t channel, int8_t signal);
void print_data(const struct pcap_pkthdr h, u_char *bssid, u_char * station,
		uint16_t channel, int8_t signal);
void make_json(ap_list l);
void clean(ap_list *apl, double timeout, int verbose);
void free_aps(ap_list *apl);


