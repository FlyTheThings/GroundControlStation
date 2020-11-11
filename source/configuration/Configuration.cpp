#include <Configuration.hpp>


NetworkConfiguration Configuration::network;
OriginConfiguration Configuration::origin;
StyleConfiguration Configuration::style;
TTSConfiguration Configuration::tts;


void Configuration::ReadAll(void){
    network.Read();
    origin.Read();
    style.Read();
    tts.Read();
}

