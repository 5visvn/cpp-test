#include <iostream>


enum Direction{North, South, East, West};

class MapSite{
public:
   virtual void enter() = 0;
};

class Room : public MapSite {
public:
   Room(int roomNo);
   MapSite* getSide(Direction) const;
   virtual void setSide(Direction, MapSite*) override;
   void enter();
private:
   MapSite* sides[4];
   int roomNumber;
};

class Wall : public MapSite {
public:
   Wall();
   virtual void enter() override;
};

class Door : public MapSite {
public:
   Door(Room*, Room*);
   virtual void enter() override;
   Room* otherSide(Room*);
private:
   Room* rooms[2];
   bool isOpen;
};



class Maze {
public:
   Maze();
   void AddRoom(Room*);
   Room* getRoom(int) const;
private:

};

class MazeGame {
};

class MazeFactory {
public:
   MazeFactory();
   
};
