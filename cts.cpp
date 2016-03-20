#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <exception>
#include <array>
#include<time.h>
using namespace std;


class messageHeader
{
private:
string messageCateogry;
string messageType;
string messageNetwork;
string retransmissionReq;
string messageHeaderIdentifer;
string transcationIdPartA;
string messageSequenceNumber;
string participantId;
string CTStimeStamp;
string timeStamp1;
string timeStamp2;
string transcationIdPartB;
string y;

public:
messageHeader(){};
messageHeader(string inputBuf)
{
 // the 45 characters are appended into each string depending on their
placement.
messageCateogry.append(inputBuf,0,1);
messageType.append(inputBuf,1,1);
messageNetwork.append(inputBuf,2,1);
retransmissionReq.append(inputBuf,3,2);
messageHeaderIdentifer.append(inputBuf,5,1);
transcationIdPartA.append(inputBuf,6,2);
messageSequenceNumber.append(inputBuf,8,9);
participantId.append(inputBuf,17,1);
CTStimeStamp.append(inputBuf,18,6);
timeStamp1.append(inputBuf,24,6);
timeStamp2.append(inputBuf,30,6);
transcationIdPartB.append(inputBuf,36,9);
}
string getCTStimeStamp()
{
string x= CTStimeStamp;
long long int number[6];
long long int number1[6];
long long int sum=0;
for (int count=0,y=5; count < 6,y>=0; count++,y--)
{
sum += (x[count]-32)*pow(95,y);
 }
long long int timestamp = sum;
long milliseconds = (long) (timestamp / 1000) % 1000;
long seconds = (((long) (timestamp / 1000) - milliseconds)/1000)%60 ;
long minutes = (((((long) (timestamp / 1000) - milliseconds)/1000) - seconds)/60) %60
;
long hours = ((((((long) (timestamp / 1000) - milliseconds)/1000) - seconds)/60) -
minutes)/60;

stringstream ss;
ss <<hours<<":"<<minutes<<":"<<seconds<<"."<<milliseconds<<endl;
string CMTime;
ss >>CMTime;
return CMTime;
}
string getTimeStamp1()
{
string x= timeStamp1;
long long int sum=0;
for (int count=0,y=5; count < 6,y>=0; count++,y--)
{
sum += (x[count]-32)*pow(95,y);
 }
 stringstream ss;
ss<<sum;
string tStamp1;
ss>>tStamp1;
return tStamp1;
}
string getTimeStamp2()
{
string x= timeStamp2;
long long int sum=0;
for (int count=0,y=5; count < 6,y>=0; count++,y--)
{
sum += (x[count]-32)*pow(95,y);
 }
 stringstream ss1;
ss1<<sum;
string tStamp2;
ss1>>tStamp2;
return tStamp2;
}
string getTransIDB()
{
string x= transcationIdPartB;
long long int number[9];
long long int number1[9];
long long int sum=0;
for (int count=0,y=5; count < 9,y>=-3; count++,y--)
{
sum += (x[count]-32)*pow(95,y);
 }
 stringstream ss;
ss<<sum;
string transIDB;
ss>>transIDB;
return transIDB;
}
string getMessageCat()
{
return messageCateogry;
}
string getMessageType()
{
return messageType;
}
string getMessageNetwork()
{
return messageNetwork;
}
string getMessageSqNum()
{
return messageSequenceNumber;
}
string getPartID()
{
return participantId;
}
};


class longTrade : public messageHeader //inherits the getters and entities from
message header.
{
 
private:
 string securitySymbol;
string temporarySuffix;
string testMsgIndicator;
string tradeRprtFacID; //TRFidentifer
string primaryListMkPartID;
string reserved;
string FinancialStat;
string currIndicator;
string heldTrID;
string InstrType;
string SellersSaleDay;
string saleCondition;
string TradeThruExID;
string ShortSaleRestID;
string Reserved2;
string PriceDenoID;
string tradePrice;
string tradeVolume;
string consolidHiLoID;
string partOpHiLoLastID;
string reserved3;
string stopStockID;

public:
longTrade( string inputBuf2) // Default constructor includes messageHeader
constructor so first 45 bites
: messageHeader(inputBuf2) // are sent to messageHeader while the
remaining go through longTrade.
{
securitySymbol.append(inputBuf2,45,11);
temporarySuffix.append(inputBuf2,56,1);
testMsgIndicator.append(inputBuf2,57,1);
tradeRprtFacID.append(inputBuf2,58,1);
primaryListMkPartID.append(inputBuf2,59,1);
reserved.append(inputBuf2,60,1);
FinancialStat.append(inputBuf2,61,1);
currIndicator.append(inputBuf2,62,3);
heldTrID.append(inputBuf2,65,1);
InstrType.append(inputBuf2,66,1);
SellersSaleDay.append(inputBuf2,67,3);
saleCondition.append(inputBuf2,70,4);
TradeThruExID.append(inputBuf2,74,1);
ShortSaleRestID.append(inputBuf2,75,1);
Reserved2.append(inputBuf2,76,1);
PriceDenoID.append(inputBuf2,77,1);
tradePrice.append(inputBuf2,78,12);
tradeVolume.append(inputBuf2,90,9);
consolidHiLoID.append(inputBuf2,99,1);
partOpHiLoLastID.append(inputBuf2,100,1);
reserved3.append(inputBuf2,101,1);
stopStockID.append(inputBuf2,102,1);
}
string getSecuirtySymbol()
{
stringstream ss;
ss <<securitySymbol<<","; // removes the trailing white spaces for
longtrades.
string secsym;
ss >>secsym;
return secsym;
}
string getSecurityPrice()
{
stringstream rr;
rr <<tradePrice;
double tradePriceNum;
rr >> tradePriceNum;
if ( PriceDenoID == "D")
{
tradePriceNum = tradePriceNum/10000;
}
else
{
tradePriceNum = tradePriceNum/100;
}
rr.clear();
rr <<tradePriceNum;
tradePrice.clear();
rr >> tradePrice;
return tradePrice;
}
string getTradeVolume()
{
stringstream ff;
ff << tradeVolume;
long tradeVol;
ff >> tradeVol;
ff.clear();
ff << tradeVol;
ff >> tradeVolume;
return tradeVolume;
}
string getSaleCondition()
{
stringstream ss;
ss << saleCondition;
string SC;
ss >> SC;
return SC;
}
string TRF()
{
return tradeRprtFacID;
}
};


class shortTrade : public messageHeader //inherits the getters and entities from message
header.
{
 
private:
string securitySymbol;
string saleCondition;
string tradeVolume;
string priceDenomID;
string tradePrice;
string consolidHiLow;
string partciOpenHiLow;
string reserved;
string transactionIDB;

public:
shortTrade(string inputbuf3) // Default constructor includes messageHeader
constructor so first 45 bites
:messageHeader(inputbuf3) // are send to messageHeader while the remaining
go through shortTrade.
{
securitySymbol.append(inputbuf3,45,3);
saleCondition.append(inputbuf3,48,1);
tradeVolume.append(inputbuf3,49,4);
priceDenomID.append(inputbuf3,53,1);
tradePrice.append(inputbuf3,54,8);
consolidHiLow.append(inputbuf3,62,1);
partciOpenHiLow.append(inputbuf3,63,1);
reserved.append(inputbuf3,64,1);
}
string getSecuirtySymbol()
{
stringstream ss;
return securitySymbol;
ss <<securitySymbol;
string secsym;
ss >>secsym;
return secsym;
}
string getSecurityPrice()
{
stringstream rr;
rr <<tradePrice;
double tradePriceNum;
rr >> tradePriceNum;
if ( priceDenomID == "D")
{
tradePriceNum = tradePriceNum/10000;
}
else
{
tradePriceNum = tradePriceNum/100;
}
rr.clear();
rr <<tradePriceNum;
tradePrice.clear();
rr >> tradePrice;
return tradePrice;
}
string getTradeVolume()
{
stringstream ff;
ff << tradeVolume;
long tradeVol;
ff >> tradeVol;
ff.clear();
ff << tradeVol;
ff >> tradeVolume;
return tradeVolume;
}
string getSaleCondition()
{
stringstream ss;
ss << saleCondition;
string SC;
ss >> SC;
return SC;
}
};


int main()
{
string masterBuffer;
ifstream inputFile;
ofstream outputFile;
inputFile.open("C:/Users/ISURU_000/Desktop/THIS.txt",ios::in,ios::binary);
outputFile.open("FixedFormat.txt");

while(getline(inputFile,masterBuffer)) //Imports data line by line into the
buffer
{
 
if ( masterBuffer[1] == 'I') // if the second character of every
line is 'I',
{ // the line is loaded into a short trade
object.
shortTrade sTrade(masterBuffer);
outputFile
<<sTrade.getCTStimeStamp()+","+sTrade.getTimeStamp1()+sTrade.getTimeStamp2()+","+
sTrade.getTransIDB()+","+sTrade.getMessageCat()+","+sTrade.getMessageType()+","+sT
rade.getMessageNetwork()+","+
sTrade.getMessageSqNum()+","+sTrade.getPartID()+","+sTrade.getSecuirtySymbol()+","
+sTrade.getSecurityPrice()+","+
sTrade.getTradeVolume()+","+sTrade.getSaleCondition()<<endl;
masterBuffer.clear();
getline(inputFile,masterBuffer);
}

else if (masterBuffer[1] == 'B') // if the second character of every line
is 'B', 
{ // the line is loaded into a long trade
object.
longTrade lTrade(masterBuffer);
outputFile <<
lTrade.getCTStimeStamp()+","+lTrade.getTimeStamp1()+","+lTrade.getTimeStamp2()+","+lTrade
.getTransIDB()+
","+lTrade.getMessageCat()+","+lTrade.getMessageType()+","+lTrade.getMessageNetwor
k()+","+lTrade.getMessageSqNum()+
","+lTrade.getPartID()+","+lTrade.getSecuirtySymbol()+","+lTrade.getSecurityPrice(
)+","+lTrade.getTradeVolume()+
","+lTrade.getSaleCondition()+","+lTrade.TRF()<<endl;
masterBuffer.clear();
getline(inputFile,masterBuffer);
}
}

inputFile.close();
outputFile.close();

system("pause");
return 0;
}
