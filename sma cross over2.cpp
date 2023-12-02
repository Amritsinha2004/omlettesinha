#include <iostream>
#include <vector>
using namespace std;
double calculateSMA (const vector<double>&data,int period){
    if(data.size()<period){
        cerr<<"insufficient data as period size must me lesser than no.of data given"<<endl;
        return 0.0;
    }
    double sum=0.0;
    for(int i=data.size()-period;i<data. size();i++){
        sum=sum+i;
    }
    return sum/period;

}
int main(){
    vector<double>asset_prices;
    int n;
    cout<<"enter the no. of prices you need"<<endl;
    cin>>n;
    double price;
    cout<<"enter the prices"<<endl;
    for(int i=0;i<n;i++){
        cin>>price;
        asset_prices.push_back(price);

    }
    int shortperiod;
    int longperiod;
    cout<<"enter moving averages"<<endl;
    cin>>shortperiod>>longperiod;
    double shortterm=calculateSMA(asset_prices,shortperiod);
    double longterm=calculateSMA(asset_prices,longperiod);
    bool buysiganl=(shortterm>longterm);
    double entry=asset_prices.back();
    double sl=(entry*90)/100;
    double target=(entry*120)/100;
    if(buysiganl){
        cout<<"buy"<<endl;
        cout<<"strike price will be "<<entry<<endl;
        cout<<"stoploss will be "<<sl<<endl;;
        cout<<"target will be "<<target<<endl;
    }
    else{
        cout<<"don't make new positions or sell ";
    }
    int amount;
    cout<<"enter amount to invest";
    cin>>amount;
    int quant;
    quant=amount/entry;
    double loss=sl*quant;
    double targ= target*quant;
    cout<<"total quantity = "<<quant<<endl;
    cout<<"loss if sl hits = "<<loss<<endl;
    cout<<"profit if target hits = "<<targ<<endl;



}