// This file will provide handler for 
#pragma once

#include "http_handler.h"

using namespace web;

class NcwebServiceHandler {
public:
	std::vector<utility::string_t> path;
	std::map<utility::string_t,utility::string_t> query;
   
	void NcwebResponseHandler(int status , http_request& message);
	void NcwebGetServiceHandler(std::vector<utility::string_t> path, 
        std::map<utility::string_t,utility::string_t> query, http_request message);    
};
