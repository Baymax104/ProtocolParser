

#define HAVE_REMOTE

#include <iostream>
#include <pcap.h>

int main() {
    pcap_if_t *alldevs;
    pcap_if_t *d;
    int i=0;
    char errbuf[PCAP_ERRBUF_SIZE];
    char* a = PCAP_SRC_IF_STRING;

    /* 获取本地机器设备列表 */
    if (pcap_findalldevs_ex(a, nullptr, &alldevs, errbuf) == -1) {
        fprintf(stderr,"Error in pcap_findalldevs_ex: %s\n", errbuf);
        exit(1);
    }

    /* 打印列表 */
    for(d=alldevs; d!=nullptr; d=d->next) {
        printf("%d. %s", ++i, d->name);
        if (d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }

    if (i == 0) {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
        return 0;
    }

    pcap_freealldevs(alldevs);
}
