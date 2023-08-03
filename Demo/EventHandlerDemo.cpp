/**
 * Created by TekuConcept on June 12, 2017
 */

#include <iostream>
#include <memory>
#include "EventHandler.h"
#include "FunctionCommand.h"
#include "StaticCommand.h"

#define DMSG(x) std::cout << x << std::endl

class DummyCommandA : public EventCommand<EventArgs> {
public:
    void invoke(Object& sender, EventArgs e) {
        (void)sender;
        (void)e;        
        DMSG("Dummy Command A Executed!");
    }
};

class DummyCommandB {
public:
    void callback(Object& sender, EventArgs e) {
        (void)sender;
        (void)e;
        DMSG("Dummy Command B Executed!");
    }
};

void static_callback(Object& sender, EventArgs e) {
    (void)sender;
    (void)e;
    DMSG("Static Callback Executed!");
}



void testEvent(EventHandler<EventArgs> handler) {
    Object obj(typeid(int), NULL);
    EventArgs e;
    handler.invoke(obj, e);
}

int main() {
    DMSG("- EVENT HANDLER DEMO -");
    
    DummyCommandB cmd;
    
    EventHandler<EventArgs> handler;
    handler += std::make_shared<DummyCommandA>();
    handler += FunctionCommandPtr(DummyCommandB,EventArgs,cmd,callback);
    handler += StaticCommandPtr(EventArgs,static_callback);
    handler += LambdaCommandPtr(EventArgs,[&](Object&,EventArgs){
        DMSG("Lambda Callback Executed!");
    });
    testEvent(handler);
    
    DMSG("- DEMO FINISHED -");
    return 0;
}