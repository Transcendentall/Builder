#include <iostream>

using namespace std;

struct FundamentOfHouse
{
    unsigned short int area = 0;
};
struct WallsOfHouse
{
    unsigned short int countw = 0;
    std::string material = "";
};
struct DoorsOfHouse
{
    unsigned short int countw = 0;
    std::string material = "";
};
struct RoofOfHouse
{
    std::string material = "";
};
struct WindowsOfHouse
{
    unsigned short int countw = 0;
    std::string material = "";
};
struct WaterpoolsOfHouse
{
    unsigned short int countw = 0;
    unsigned short int volume = 0;
};

class House
{

private:


public:
    FundamentOfHouse Fundament;
    WallsOfHouse Walls;
    RoofOfHouse Roof;
    DoorsOfHouse Doors;
    WindowsOfHouse Windows;
    WaterpoolsOfHouse Waterpools;

    void WriteHouse()
{
  cout << endl;
  if (this->Fundament.area!=0) { cout << " - Fundament.      Area     = " << this->Fundament.area << endl; }
  if (this->Walls.countw!=0) { cout << " - Walls.          Count    = " << this->Walls.countw << ";   Material = " << this->Walls.material << endl; }
  if (this->Doors.countw!=0) { cout << " - Doors.          Count    = " << this->Doors.countw << ";   Material = " << this->Doors.material << endl; }
  if (this->Roof.material!="") { cout << " - Roof.           Material = " << this->Roof.material << endl; }
  if (this->Windows.countw!=0) { cout << " - Windows.        Count    = " << this->Windows.countw << ";   Material = " << this->Windows.material << endl; }
  if (this->Waterpools.countw!=0) { cout << " - Waterpools.     Count    = " << this->Waterpools.countw << ";   Volume = " << this->Waterpools.volume << endl; }
  cout << endl;
  cout << "------------------" << endl;
  cout << endl;
}

protected:


};

class Builder
{
public:
  virtual void CreateHouse()
   {

   }

    virtual void BuildFundament(unsigned short int cw)
   {

   }
    virtual void BuildWalls(unsigned short int cw)
   {

   }
    virtual void BuildRoof()
   {

   }
    virtual void BuildDoors(unsigned short int cw)
   {

   }
    virtual void BuildWindows(unsigned short int cw)
   {

   }
   virtual void BuildWaterpools(unsigned short int cw, unsigned short int vol)
   {

   }

  virtual House* GetResult()
  {
      return nullptr;
  }
};




class WoodBuilder : public Builder
{
private:
  House* currentBuilder;

public:
  WoodBuilder()
  {
    currentBuilder = nullptr;
  }

  virtual void CreateHouse()
  {
    currentBuilder = new House();
  }
  virtual void BuildFundament(unsigned short int cw)
  {
    currentBuilder->Fundament.area = cw;
  }
  virtual void BuildWalls(unsigned short int cw)
  {
    currentBuilder->Walls.countw = cw;
    currentBuilder->Walls.material = "Wood";
  }
  virtual void BuildRoof()
  {
    currentBuilder->Roof.material = "Wood";
  }
  virtual void BuildDoors(unsigned short int cw)
  {
    currentBuilder->Doors.countw = cw;
    currentBuilder->Doors.material = "Iron";
  }
  virtual void BuildWindows(unsigned short int cw)
  {
    currentBuilder->Windows.countw = cw;
    currentBuilder->Windows.material = "Wood";
  }
  virtual void BuildWaterpools(unsigned short int cw, unsigned short int vol)
  {
    currentBuilder->Waterpools.countw = cw;
    currentBuilder->Waterpools.volume = vol;
  }

  virtual House* GetResult()
  {
    return currentBuilder;
  }

  ~WoodBuilder()
  {
    if (currentBuilder != nullptr)
      delete currentBuilder;
  }
};


class StoneBuilder : public Builder
{
private:
  House* currentBuilder;

public:
  StoneBuilder()
  {
    currentBuilder = nullptr;
  }

  virtual void CreateHouse()
  {
    currentBuilder = new House();
  }
  virtual void BuildFundament(unsigned short int cw)
  {
    currentBuilder->Fundament.area = cw;
  }
  virtual void BuildWalls(unsigned short int cw)
  {
    currentBuilder->Walls.countw = cw;
    currentBuilder->Walls.material = "Stone";
  }
  virtual void BuildRoof()
  {
    currentBuilder->Roof.material = "Tile";
  }
  virtual void BuildDoors(unsigned short int cw)
  {
    currentBuilder->Doors.countw = cw;
    currentBuilder->Doors.material = "Steel";
  }
  virtual void BuildWindows(unsigned short int cw)
  {
    currentBuilder->Windows.countw = cw;
    currentBuilder->Windows.material = "Iron";
  }
  virtual void BuildWaterpools(unsigned short int cw, unsigned short int vol)
  {
    currentBuilder->Waterpools.countw = cw;
    currentBuilder->Waterpools.volume = vol;
  }

  virtual House* GetResult()
  {
    return currentBuilder;
  }

  ~StoneBuilder()
  {
    if (currentBuilder != nullptr)
      delete currentBuilder;
  }
};



class Director
{
public:

void BuildSimpleHouse(Builder& builder)
  {
    builder.CreateHouse();
    builder.BuildFundament(30);
    builder.BuildWalls(4);
    builder.BuildRoof();
    builder.BuildDoors(1);
    builder.BuildWindows(3);
  }
void BuildBigHouseWithWaterpool(Builder& builder)
  {
    builder.CreateHouse();
    builder.BuildFundament(100);
    builder.BuildWalls(8);
    builder.BuildRoof();
    builder.BuildDoors(2);
    builder.BuildWindows(12);
    builder.BuildWaterpools(1, 26);
  }
void BuildVerySmallHouseWithoutRoofANDWindows(Builder& builder)
  {
    builder.CreateHouse();
    builder.BuildFundament(6);
    builder.BuildWalls(4);
    builder.BuildDoors(1);
  }
};



int main()
{
  House* House1;
  House* House2;
  House* House3;
  WoodBuilder Builder1W;
  StoneBuilder Builder2S;
  Director Director1;

  Director1.BuildSimpleHouse(Builder1W);
  House1 = Builder1W.GetResult();

  Director1.BuildBigHouseWithWaterpool(Builder2S);
  House2 = Builder2S.GetResult();

  Director1.BuildVerySmallHouseWithoutRoofANDWindows(Builder1W);
  House3 = Builder1W.GetResult();

  cout << endl << "------------------" << endl << endl << "FIRST  HOUSE:" << endl;
  House1->WriteHouse();
  cout << endl << "------------------" << endl << endl << "SECOND HOUSE:" << endl;
  House2->WriteHouse();
  cout << endl << "------------------" << endl << endl << "THIRD  HOUSE:" << endl;
  House3->WriteHouse();



  return 0;
}
