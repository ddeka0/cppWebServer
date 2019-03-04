
#include "../include/Ncweb_service_handler.h"

void NcwebServiceHandler::NcwebResponseHandler(int status, http_request& message) {
    switch(status) {
       case HTTP_OK:
           message.reply(status_codes::OK);           
           return;

       case HTTP_CREATED:
           message.reply(status_codes::Created);           
           return;
                      
       case HTTP_BADREQUEST:    
           message.reply(status_codes::BadRequest);           
           return; 
       
       case HTTP_FORBIDDEN:     
           message.reply(status_codes::Forbidden);           
           return; 
                  
       case HTTP_NOTFOUND:
           message.reply(status_codes::NotFound);          
           return; 
                  
       case LENGTHREQUIRED:
            message.reply(status_codes::LengthRequired);           
           return; 
           
       case PRECONDITIONFAILED:           
            message.reply(status_codes::PreconditionFailed);           
           return;
         
        default:   return; 
   }; 
}
void NcwebServiceHandler::NcwebGetServiceHandler(std::vector<utility::string_t> path,
    std::map<utility::string_t,utility::string_t> query, http_request message) {
    


    
}