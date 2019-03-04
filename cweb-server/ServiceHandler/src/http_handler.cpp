#include "../include/http_handler.h"
#include "../include/Ncweb_service_handler.h"


handler::handler() {
    // empty constructor    
}


handler::handler(utility::string_t url):m_listener(url) {
    m_listener.support(methods::GET, std::bind(&handler::handle_get, this, std::placeholders::_1));
    m_listener.support(methods::PUT, std::bind(&handler::handle_put, this, std::placeholders::_1));
    m_listener.support(methods::POST, std::bind(&handler::handle_post, this, std::placeholders::_1));
    m_listener.support(methods::DEL, std::bind(&handler::handle_delete, this, std::placeholders::_1));
}

handler::~handler() {
    // empty destructor
}

void handler::handle_error(pplx::task<void>& t) {
    try {        
        t.get();
    }
    catch(...) {
        // Ignore the error, Log it if a logger is available
    }
}


void handler::handle_get(http_request message)
{   
    BOOST_LOG_TRIVIAL(debug)<<"Method: GET";   
    return;    
}
    

void handler::handle_post(http_request message)
{
    auto path  = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
    
    json::value tjson_data;

    message.extract_json()     //extracts the request content into a json
		.then([&tjson_data](pplx::task<json::value> task)
	{
		tjson_data = task.get();
	})
    .wait();
        
    return;
};

void handler::handle_delete(http_request message)
{
    ucout <<  message.to_string() << endl;

    string rep = U("WRITE YOUR OWN DELETE OPERATION");
    message.reply(status_codes::OK,rep);
    return;
};



void handler::handle_put(http_request message)
{      
    BOOST_LOG_TRIVIAL(debug)<<"Method: PUT";

    return;
};