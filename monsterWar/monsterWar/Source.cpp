#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
class vex
{
public:
	float x;
	float y;
	float angle = atan2(x, y) * 180 / 3.1415926f;
	vex();
	vex(float x, float y);
};
struct Entity
{

	unsigned short ID;
	unsigned short TypeID;
	float X;
	float Y;
	float FX;
	float FY;
	char pad[12];
};
struct EntityArray
{
	unsigned short ID;
	unsigned short TypeID;
	float X;
	float Y;
	float FX;
	float FY;
	char pad[12];
	bool collision = false;
	int ColliderBuddy;
};
void main()
{
	std::fstream file;
	Entity entity;
	EntityArray entities[137];
	int i = 0;
	file.open("map.bin", std::ios_base::in, std::ios_base::binary);
	std::ifstream fin("map.bin", std::ios_base::in | std::ios_base::binary);
	if (fin.good())
	{

		unsigned int entityCount = -1;
		fin.read((char*)&entityCount, sizeof(unsigned));

		while (!fin.eof() && fin.peek() != EOF)
		{

			fin.read((char*)&entity, sizeof(Entity));
			std::cout << entity.ID << " " << entity.TypeID << " " << entity.X << " " << entity.Y << " " << entity.FX << " " << entity.FY << std::endl;
			entities[i].ID = entity.ID;
			entities[i].TypeID = entity.TypeID;
			entities[i].X = entity.X;
			entities[i].Y = entity.Y;
			entities[i].FX = entity.FX;
			entities[i].FY = entity.FY;
			i++;
		}
		int x = 54;
		while (x != 137)
		{
			for (int y = (x + 1); y < 137; y++)
			{
				if (entities[x].TypeID == 3)
				{
					float distance = sqrt(((entities[y].X - entities[x].X) * (entities[y].X - entities[x].X)) + ((entities[y].Y - entities[x].Y) * (entities[y].Y - entities[x].Y)));
					vex troll(entities[x].FX, entities[x].FY);
					if (distance <= 12)
					{
						entities[x].collision = true;
						printf(" COLLISION \n");
					}
				}
				if (entities[x].TypeID == 4)
				{
					float distance = sqrt(((entities[y].X - entities[x].X) * (entities[y].X - entities[x].X)) + ((entities[y].Y - entities[x].Y) * (entities[y].Y - entities[x].Y)));
					if (distance <= 10)
					{
						entities[x].collision = true;
						printf(" COLLISION \n");
					}
				}
				if (entities[x].TypeID == 5)
				{
					float distance = sqrt(((entities[y].X - entities[x].X) * (entities[y].X - entities[x].X)) + ((entities[y].Y - entities[x].Y) * (entities[y].Y - entities[x].Y)));
					if (distance <= 25)
					{
						entities[x].collision = true;
						printf(" COLLISION \n");
					}
				}
			}
			x++;
		}


		// 54-88 troll      C-12
		//89-115 Imp        C-10
		//116-136 // ogre   C-25
		/*  for (int i = 0; i < 137; i++)
		{
		fin.read((char*)&entity, sizeof(Entity));
		std::cout << entities[i].ID << " " << entities[i].TypeID << " " << entities[i].X << " " << entities[i].Y << " " << entities[i].FX << " " << entities[i].FY << std::endl;
		}*/

		/*while (!fin.eof() && fin.peek() != EOF)
		{
		fin.read((char*)&entity, sizeof(Entity));
		std::cout << entity.ID << " " << entity.x << " " << entity.y << std::endl;
		}
		fin.close();*/
	}
	/*unsigned size;
	Entity *entity;
	if (file.is_open())
	{
	file.read((char*)&size, sizeof(int));
	entity = new Entity[size];
	file.read((char*)entity, sizeof(Entity) * size);
	}
	file.close();*/
	system("pause");
}