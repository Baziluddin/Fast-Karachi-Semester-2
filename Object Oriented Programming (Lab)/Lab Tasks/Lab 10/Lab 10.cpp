
//24K-0559 BAZIL-UDDIN-KHAN
#include <iostream>
#include<fstream>


int main()
{
    std :: ifstream stream;
    
    stream.open("vehicles.txt");
    if(!stream)
    {
        std :: cerr << "Sorry!. Cant Open " << std::endl;
        return 1;
    }
    
    std :: cout << "Successfully Login" << std::endl;
    std::string Word;
    
    while(getline(stream,Word))
    {
        std::cout << Word << std::endl;
    }

    return 0;
}
// Q2
// 24k-0559 baziluddinkhan
#include <iostream>
#include<fstream>
#include<sstream>
int main()
{
    std::ifstream stream;
    
    stream.open("vehicles.txt");
    if(!stream)
    {
        std::cerr << "Sorry!. Cant Open " << std::endl;
        return 1;
    }
    
    std::cout << "Successfully Login" << std::endl;
    std::string Word;
    std::string Year;
    std::string Certification;
    std::string ExtraData;
    std::string Type;
    std::string Name;
    std::string ID;
    
    while(getline(stream,Word))
    {
        std::cout << Word << std::endl;
        std::istringstream Stream(Word); 
        getline(Stream, Type, ',');
        getline(Stream, ID, ',');
        getline(Stream, Name, ',');
        getline(Stream, Year, ',');
        getline(Stream, ExtraData, ',');
        getline(Stream, Certification, ',');
            
        
        std::cout << "Certificate is = " << Certification << std::endl;
        std::cout << "Year is = "<< Year << std::endl;
        std::cout << "Extra Data = " << ExtraData << std::endl;
        std::cout << "Id is = " << ID << std::endl;
        std::cout << " name is " << Name << std::endl;
        std::cout << "Type is " << Type << std::endl;
    }
    
    stream.close();

    return 0;
}
// Q3
// 24K-0559 BAZIL-UDDIN-KHAN
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

int main()
{
    std::ifstream stream;
    
    stream.open("vehicles.txt");
    if(!stream)
    {
        std::cerr << "Sorry!. Cant Open " << std::endl;
        return 1;
    }
    
    std::cout << "Successfully Login" << std::endl;
    std::string Word;
    std::string Year;
    std::string Certification;
    std::string ExtraData;
    std::string Type;
    std::string Name;
    std::string ID;
    int Y=0;

    while(getline(stream,Word))
    {
        std::cout << Word << std::endl;
        std::istringstream Stream(Word);
         
        getline(Stream, Type, ',');
        getline(Stream, ID, ',');
        getline(Stream, Name, ',');
        getline(Stream,Word,',');
        int year = stoi(Word);
        getline(Stream, ExtraData, ',');
        getline(Stream, Certification, ',');
        std::cout << "Certificate is = " << Certification << std::endl;
        
        std::cout << "Extra Data = " << ExtraData << std::endl;
        std::cout << "Id is = " << ID << std::endl;
        std::cout << " name is " << Name << std::endl;
        std::cout << "Type is " << Type << std::endl;
        std::cout << "Year is " << year << std::endl;

        Y++;
    }
    
    stream.close();


    return 0;
}
//Q4
// 24k-0559 baziluddinkhan
#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>
int main()
{
    std::ifstream stream;
    
    stream.open("vehicles.txt");
    if(!stream)
    {
        std::cerr << "Sorry!. Cant Open " << std::endl;
        return 1;
    }
    
    std::cout << "Successfully Login" << std::endl;
    std:: string Word;
    std:: string Type;
    std::string ExtraData;
    std::string ID;
    
    while(getline(stream,Word))
    {
        std::cout << Word << std::endl;
        std::istringstream Stream(Word); 
        getline(Stream, Type, ',');
        getline(Stream, ExtraData, ',');
        getline(Stream,ID,',');
        std::cout << "Extra Data = " << ExtraData << std::endl;
        std::cout << "Type is " << Type << std::endl;
        std::cout << "ID is " << ID << std::endl;

        size_t pos = ExtraData.find(":");
        if(pos != std::string::npos && Type == "AutonomousCar")
        {
            std::string sd = ExtraData.substr(pos+1,ExtraData.size());
            float val = stof(sd);
            std::cout <<"It is Autunomous Car with software version is " << val << std::endl;
        }
        
        else if(pos != std::string::npos && Type == "ElectricVehicle")
        {
            std::string sd = Type.substr(pos+1,Type.size());
            int val = stoi(sd);
            std::cout <<"It is Electric Vehicle with Battery Capacity: " << val << std::endl;
        }
    }
    
    stream.close();

    return 0;
}
// Q5
// 24k-0559 baziluddinkhan
#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>
int main()
{
    std::ifstream stream;
    
    stream.open("vehicles.txt");
    if(!stream)
    {
        std::cerr << "Sorry!. Cant Open " << std::endl;
        return 1;
    }
    
    std::cout << "Successfully Login" << std::endl;
    std:: string Word;
    std:: string Type;
    std::string ExtraData;
    std::string ID;
    std::string Name;
    
    while(getline(stream,Word))
    {
        std::cout << Word << std::endl;
        std::istringstream Stream(Word); 
        getline(Stream, Type, ',');
        getline(Stream,ID,',');
        getline(Stream,Name,',');
        getline(Stream,Word,',');
        getline(Stream, ExtraData, ',');
    
        std::cout << "Extra Data = " << ExtraData << std::endl;
        std::cout << "Type is " << Type << std::endl;
        std::cout << "ID is " << ID << std::endl;

        size_t pos = ExtraData.find(":");
        if(pos != std::string::npos && Type == "AutonomousCar")
        {
            std::string sd = ExtraData.substr(pos+1);
            float val = stof(sd);
            std::cout <<"It is Autunomous Car " << val << std::endl;
        }
        
        else if(pos != std::string::npos && Type == "ElectricVehicle")
        {
            std::string sd = ExtraData.substr(pos+1);
            int val = stoi(sd);
            std::cout <<"It is Electric Vehicle " << val << std::endl;
        }

        else if(Type == "HybridTruck")
        {
            size_t pos = ExtraData.find(":");
            size_t po = ExtraData.find("|");

            if(pos != std::string::npos && po != std::string::npos)
            {
                std::string cargoval = ExtraData.substr(pos+1,po-pos-1);
                int Cargo = stoi(cargoval);

                size_t batterypos = ExtraData.find("Battery:");
                if(batterypos != std::string::npos)
                {
                    std::string battert = ExtraData.substr(batterypos+8);
                    int ba = stoi(battert);

                    std :: cout << "It is a Hybrid Truck wit Cargo capacity " << Cargo << "and battery capacity: " << ba << std::endl;
                }
                else{
                    std::cout << "Battery info not found" << std::endl;
                }
            }
            else
            {
                std::cout<<"sorry cargo details like | not found " << std::endl;
            }

        }
        else
        {
            std::cout<<"No Such Vehicles Matched" << std::endl;
        }
    }
    
    stream.close();

    return 0;
}
// Q6
//24k-0559 Bazil-uddin-khan
#include<iostream>
#include<fstream>
#include<cstring>

class InventorySystem
{
    public:
    char itemName[20];
    int itemID;

};

int main()
{
    InventorySystem inventory;
    inventory.itemID = 112;
    strcpy(inventory.itemName,"Laptop");

    std::ofstream stream("inventoy.dat",std::ios::binary);
    if(!stream)
    {
        std::cerr<<"Error in opening file" << std::endl;
        return 0;
    }

    stream.write((char*)&inventory,sizeof(inventory));
    stream.close();
    
    InventorySystem inven;
    std::ifstream streamd("inventoy.dat",std::ios::binary);
    if(!streamd)
    {
        std::cerr<<"Error in opening file" << std::endl;
        return 0;
    }

    streamd.read((char*)&inven,sizeof(inven));
    streamd.close();

    std::cout << "ID IS :" << inven.itemID << std::endl;
    std::cout << "Name IS :" << inven.itemName << std::endl;
}
// Q7
//24k-0559 Bazil-uddin-khan
#include<iostream>
#include<fstream>
#include<string>

int main()
{
    std :: ofstream writefile;

    writefile.open("sensor_log.txt");

    if(!writefile)
    {
        std::cerr << "Sorry!. Login Unsussesfull" << std::endl;
        return 1;
    }

    std::cout<<"Sucessful login" <<std::endl;

    writefile << "Sensor 1: 25.5 C\n";
    std::streampos Pos1 = writefile.tellp();
    std::cout << " Pos position after first write " << Pos1 << std::endl;

    writefile << "Sensor 2: 98.1 %RH\n";
    std::streampos Pos2 = writefile.tellp();
    std::cout << " Pos position after second write " << Pos2 << std::endl;
    
    writefile << "Sensor 3: 198.1 %RH\n";
    std::streampos Pos3 = writefile.tellp();
    std::cout << " Pos position after third write " << Pos3 << std::endl;

    writefile.close();

}
// Q8
//24k-0559 Bazil-uddin-khan
#include<iostream>
#include<fstream>
#include<string>

int main()
{
    std :: ofstream writefile;

    writefile.open("config.txt");

    if(!writefile)
    {
        std::cerr << "Sorry!. Login Unsussesfull" << std::endl;
        return 1;
    }

    std::cout <<"Succesful Login" << std::endl;

    writefile << "AAAA";
    writefile << "BBBB";
    writefile << "CCCC";

    writefile.close();

    std::fstream Bothfile("config.txt",std::ios::in | std::ios::out);
    if(!Bothfile)
    {
        std::cerr << "Error in opening file" << std::endl;
        return 1;
    }

    Bothfile.seekp(5,std::ios::beg);

    Bothfile << "XXXX";
    Bothfile.close();
    
    std::ifstream Readfile("config.txt");

    if(!Readfile)
    {
        std::cerr<<"Sorry unsuccesfull" << std::endl;
        return 1;
    }

    std::string filecontent;
    std::getline(Readfile, filecontent);
    std::cout <<"updated file data is " << filecontent << std::endl;
    Readfile.close();



}
// Q9
//24K-0559 BAZIL-UDDIN-KHAN
#include<iostream>
#include<fstream>

int main()
{
    std::ifstream infile;

    infile.open("large_log.txt");

    if(!infile)
    {
      std::cout << "Unsussecful In OPening " << std::endl;
      return 1;
    }

    char Temp[11];

    infile.read(Temp,10);
    std::streampos position = infile.tellg();
    int index = 0;
    std::cout << "Position Ater " << index << " read is " << position << std::endl;

    infile.read(Temp,10);
    std::streampos position1 = infile.tellg();
    std::cout << "Position Ater " << index+1 << " read is " << position1 << std::endl;
    
    infile.close();
    return 0;


}
// Q10
//24K-0559 BAZIL-UDDIN-KHAN
#include<iostream>
#include<fstream>

int main()
{
    std::ifstream infile;
    infile.open("data_records.txt");

    if(!infile)
    {
        std::cout << "Error in opening file " << std::endl;
        return 1;
    }

    infile.seekg(25,std::ios::beg);

    std::string Record;
    std::getline(infile,Record);
    std::cout << " Third Record is :" << Record << std::endl;

    infile.close();

}
