//Anushka Verma
//Headerfile
//06/09/2020
//Portfolio 1 - Project 1
#ifndef Number_h
#define Number_h
#include <string>
using namespace std;
class RolodexEntry
{
private:
    string firName, lasName, street, town, state;
    long zip;
    short szip, area, exchange, line;
    string email;
public:
    RolodexEntry(void):firName(), lasName(), street(), town(),
                       state(), zip(000000000), szip(00000),
                       area(0), exchange(0), line(0), email()
    {
        
    }
    RolodexEntry(string fname, string lname):street(), town(),
                                             state(""), zip(000000000),
                                             szip(00000), area(0),
                                             exchange(0), line(0), email() {}
    RolodexEntry(const RolodexEntry & r):firName(r.firName), lasName(r.lasName),
                                         street(r.street), town(r.town),
                                         state(r.state), zip(r.zip), szip(r.szip),
                                         area(r.area), exchange(r.exchange),
                                         line(r.line), email(r.email) {}

    string getFName() const {return firName;}
    void setFName(string first){firName = first;}
    string getLName() const {return lasName;}
    void setLName(std::string last){lasName = last;}
    string getStreet() const{return street;}
    void setStreet(string str){street = str;}
    string getTown() const {return town;}
    void setTown(string newtown){town = newtown;}
    string getState() const {return state;}
    void setState(string newstate){state = newstate;}
    long getZip() const {return zip;}
    void setZip(long newzip){zip = newzip;}
    short getSZip() const {return szip;}
    void setSZipLong(){szip = zip / 10000;}
    void setSZip(short newszip){szip = newszip;}
    short getArea() const {return area;}
    void setArea(short newarea){area = newarea;}
    short getExchange() const {return exchange;}
    void setExchange(short exch){exchange = exch;}
    short getPLine() const {return line;}
    void setPLine(short newline){line = newline;}
    std::string getEmail(){return email;}
    void setEmail(std::string Email){email = Email;}

    void printEntry();
    void readIn();
    bool isEqual(RolodexEntry e){return e.firName == firName && e.lasName == lasName &&
                                 e.street == street && e.town == town &&
                                 e.state == state && e.zip == zip && e.szip == szip &&
                                 e.area == area && e.exchange == exchange && e.line == line &&
                                 e.email == email;}
};
#endif 
