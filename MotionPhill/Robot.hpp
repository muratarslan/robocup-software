#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include "ConfigFile.hpp"
#include "Pid.hpp"

class Robot
{
	private:
	    /** robot velocity control information */
	    typedef struct VelocityCmd
	    {
		VelocityCmd() : w(0), maxWheelSpeed(127) {}

		/** velocity along x,y in team space */
		Geometry::Point2d vel;

		/** rotational velocity */
		float w;

		uint8_t maxWheelSpeed;
	    } VelocityCmd;

	public:
		Robot(ConfigFile::RobotCfg cfg);
		~Robot();

		/** Process the command for a robot and prepare output */
		void proc();

		/** clear PID windup */
		void clearPid();

                /*
		PathPlanner* pathPlanner() const { return _pathPlanner; }

		template <typename T>
		void newPathPlanner()
		{
			_pathPlanner = new T(_vision);
		}
                */
	private:
		/** given a created robot velocity, generate motor speeds */
		void genMotor(VelocityCmd velCmd);

		/** robot identification */
		const unsigned int _id;

		/** position pid **/
		Pid* _posPID;
		/** angle pid **/
		Pid* _anglePID;

		float* _motors;

                /*
		PathPlanner* _pathPlanner;
                */

		/** robot axels */
		QVector<Geometry::Point2d> _axels;
};

#endif /* ROBOT_HPP_ */