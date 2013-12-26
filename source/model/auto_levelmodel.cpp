
		#include "levelmodel.h"
		//bullet
		#include <btBulletDynamicsCommon.h>
		#include "LinearMath/btHashMap.h"

		using namespace troen;

		//!!!!!!!!!!!!! WARNING: AUTO_GENERATED !!!!!!!!!!!!!!!!!!!!!!
		// If you want to change something generally, please edit obstacle_export.py, otherwise be sure to mark changes to this code otherwise it might be overwritten


		void LevelModel::auto_addObstacles()
		{
			// obstacles
			// TODO grab the value from origin
			std::vector<BoxModel> newObstacles = {

			
			{
				btVector3(746.1251831054688, -637.6168060302734,292.9811477661133),
				btVector3(184.14979934692383, 184.14979934692383, 600.5661010742188),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, -8.4912109375,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1512.0306396484375, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, -8.4912109375,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(1186.4251708984375, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, -8.4912109375,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(860.8195495605469, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(752.2522735595703, 374.6894073486328,294.09372329711914),
				btVector3(184.14979934692383, 184.14979934692383, 600.5661010742188),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(535.2140808105469, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(94.06496047973633, -8.4912109375,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(209.60830688476562, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, -8.4912109375,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-115.997314453125, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, -8.4912109375,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-441.6028594970703, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, -8.4912109375,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-767.2085571289062, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, 1735.494384765625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, 1299.4976806640625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, 863.5012817382812,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, 427.5050354003906,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, -8.4912109375,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, -444.48760986328125,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, -880.4838562011719,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, -1316.4801025390625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1092.8141784667969, -1752.4765014648438,7.228968143463135),
				btVector3(20.0, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, 2171.490478515625,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, 1735.494384765625,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, 1299.4976806640625,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, 863.5012817382812,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, 427.5050354003906,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, -8.4912109375,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, -444.48760986328125,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, -880.4838562011719,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, -1316.4801025390625,7.228968143463135),
				btVector3(20.000009536743164, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-1418.4197998046875, -1752.4765014648438,7.228968143463135),
				btVector3(20.000009536743164, 20.000009536743164, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(342.8825378417969, 918.4856414794922,152.43303298950195),
				btVector3(1020.994873046875, 898.2110595703125, 6.920419335365295),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(568.7586212158203, -879.2779541015625,146.33319854736328),
				btVector3(683.0246734619141, 321.9303894042969, 19.53296184539795),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(988.9772033691406, 162.55023956298828,150.13311386108398),
				btVector3(288.5529136657715, 2405.4783630371094, 11.89049243927002),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-10.782455205917358, -778.228759765625,151.9006633758545),
				btVector3(531.1703491210938, 531.1703491210938, 8.442516922950745),
				btQuaternion(0.0,0.0,0.0,1.0)
			},

			{
				btVector3(-10.78243374824524, -272.44543075561523,68.1700611114502),
				btVector3(278.0600929260254, 516.7617034912109, 9.876872301101685),
				btQuaternion(1.2232740376205697e-09,0.16354946792125702,0.986535370349884,-4.369427486494715e-08)
			},

			{
				btVector3(1512.0306396484375, 2171.490478515625,7.228968143463135),
				btVector3(20.0, 20.0, 20.0),
				btQuaternion(0.0,0.0,0.0,1.0)
			} 

			};
			m_obstacles.insert(m_obstacles.end(), newObstacles.begin(), newObstacles.end());
		
			addBoxes(m_obstacles);
		}
	