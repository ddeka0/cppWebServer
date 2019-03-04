
#include <iostream>
#include <ctime>
#include <string.h> /* For strncpy */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


#include "ServiceHandler/include/Ncweb_service_handler.h"


std::unique_ptr<handler> g_http;

utility::string_t NCWEB_PORT;


void on_initialize(const string_t& address)  {    
    uri_builder uri(address);  
    
    uri.set_scheme("http");
    auto addr = uri.to_uri().to_string();    
	g_http = std::unique_ptr<handler>(new handler(addr));
    g_http->open().wait();     
    BOOST_LOG_TRIVIAL(info)<< utility::string_t(U("Listening for requests at: ")) << addr<<endl; 
    return;
}

void on_shutdown() {
	g_http->close().wait();
    return;
}

utility::string_t fReadSystem_IP(char* arg)
{
    
    int fd;
    struct ifreq ifr;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family = AF_INET;
    
    strncpy((char*)ifr.ifr_name, arg , IFNAMSIZ-1);
    
    ioctl(fd, SIOCGIFADDR, &ifr);

    close(fd);

    utility::string_t system_ip = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
    
    utility::string_t scheme = "http://";
    utility::string_t extend = ":" ;
   
    return scheme+system_ip+extend;
}

void init_configuration(){
    
    namespace pt = boost::property_tree;
    pt::ptree root;
    pt::json_parser::read_json("5gc_config.json",root);
    bool temp; 
    BOOST_LOG_TRIVIAL(info) <<"Reading system configuration file ...";
   
    NRF_PORT = root.get<string>("nrf-info.nrf-port");
        
}

int main(int argc, char *argv[]) {
   
}