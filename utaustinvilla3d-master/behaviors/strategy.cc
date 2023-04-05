#include "naobehavior.h"
#include "../rvdraw/rvdraw.h"

extern int agentBodyType;

/*
 * Real game beaming.
 * Filling params x y angle
 */
void NaoBehavior::beam( double& beamX, double& beamY, double& beamAngle ) {
    beamX = -HALF_FIELD_X + worldModel->getUNum();
    beamY = 0;
    beamAngle = 0;
}


SkillType NaoBehavior::selectSkill() {
    // My position and angle
    //cout << worldModel->getUNum() << ": " << worldModel->getMyPosition() << ",\t" << worldModel->getMyAngDeg() << "\n";

    // Position of the ball
    //cout << worldModel->getBall() << "\n";

    // Example usage of the roboviz drawing system and RVSender in rvdraw.cc.
    // Agents draw the position of where they think the ball is
    // Also see example in naobahevior.cc for drawing agent position and
    // orientation.
    /*
    worldModel->getRVSender()->clear(); // erases drawings from previous cycle
    worldModel->getRVSender()->drawPoint("ball", ball.getX(), ball.getY(), 10.0f, RVSender::MAGENTA);
    */

    // ### Demo Behaviors ###

    // Walk in different directions
    //return goToTargetRelative(VecPosition(1,0,0), 0); // Forward
    //return goToTargetRelative(VecPosition(-1,0,0), 0); // Backward
    //return goToTargetRelative(VecPosition(0,1,0), 0); // Left
    //return goToTargetRelative(VecPosition(0,-1,0), 0); // Right
    //return goToTargetRelative(VecPosition(1,1,0), 0); // Diagonal
    //return goToTargetRelative(VecPosition(0,1,0), 90); // Turn counter-clockwise
    //return goToTargetRelative(VecPdosition(0,-1,0), -90); // Turn clockwise
    //return goToTargetRelative(VecPosition(1,0,0), 15); // Circle

    // Walk to the ball
    //return goToTarget(ball);

    // Turn in place to face ball
    /*double distance, angle;
    getTargetDistanceAndAngle(ball, distance, angle);
    if (abs(angle) > 10) {
      return goToTargetRelative(VecPosition(), angle);
    } else {
      return SKILL_STAND;
    }*/

    // Walk to ball while always facing forward
    //return goToTargetRelative(worldModel->g2l(ball), -worldModel->getMyAngDeg());

    // Dribble ball toward opponent's goal
    //return kickBall(KICK_DRIBBLE, VecPosition(HALF_FIELD_X, 0, 0));

    // Kick ball toward opponent's goal
    //return kickBall(KICK_FORWARD, VecPosition(HALF_FIELD_X, 0, 0)); // Basic kick
    //return kickBall(KICK_IK, VecPosition(HALF_FIELD_X, 0, 0)); // IK kick

    // Just stand in place
    //return SKILL_STAND;

    // Demo behavior where players form a rotating circle and kick the ball
    // back and forth
    /*enum WorldObType{
        //ball 
        WO_BALL,
        //player
        WO_TEAMMATE1,
        WO_TEAMMATE2,
        WO_TEAMMATE3,
        WO_TEAMMATE4,
        WO_TEAMMATE5,
        WO_TEAMMATE6,
    };
    #define TEAMMATE_NUM 6
    
    //robot's Number
    inline int getUNum()const{
        return uNum;
    }

    //ballPosition
    inline VecPosition getBall() const{
        return worldObjects[WO_BALL].pos;
    }

    //myPosition
    inline VecPosition getMyPosition() const{
        return myPosition;
    }

    //shuaidao
    inline VecPosition getMyPosition() const{
        return myPosition;
    }

    //search player's position
    for(int i = WO_TEAMMATE1 ; i<WO_TEAMMATE1+TEAMMATE_NUM ; i++){
        VecPosition pos = worldMOdel->getOpponent(i);
    }*/

    VecPosition Posball=worldModel->getBall();
    VecPosition target[6]={
        Posball+VecPosition(-0.5,0,0),//kong qiu wei
        Posball+VecPosition(0,(Posball.getY()),0);
        Posball+VecPosition(9,4,0),//jie ying wei
        Posball+VecPosition(9,-4,o),//jie ying wei
        VecPostion((Posball.getX()-15)/2,(Posball.getY()/2+5,0)),
        VecPostion((Posball.getX()-15)/2,(Posball.getY()/2+5,0))};
    vector<vector><double>>dis(6,vector<double>(6,0));
    int BotForTarget[6]={0};
    
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            int playerNum = WO_TEAMMATE1 + j;
            WorldObject *tem = worldModel->getWorldObject(playerNum);
            if(worldModel->getUNum()==playerNum)
              Pos=me;//if bianli dao wo ,get me position
            else{
                tem=worldModel->getWorldObject(WO_TEAMMATE1 + j);
                Pos = tem->pos;//if duiyou,get duiyou position
            }
            dis[i][j]=Target[i].getDistanceTo(Pos);//dis[i][j]baocun di i ge target dao di j ming qiu yuan wei zhi
        }
    }

    for(int i=0;i<6;i++){
        int robot = min-element(dis[i].begin(),dis[i].begin()+6)-dis[i].begin();//find juli min player
        BorForTarget[i]=robot; //baocun this player ID
        for(int j=0;j<6;j++){
            dis[j][robot]=10000;//bu zai kao lv gai qiu yuan,jiang ta de ju li quan she cheng zui da
        }
        for(int i=0;i<6;i++){
            if(worldMOdel->getUNum() == WO_TEAMMATE1+BotForTarget[i]) //if bianhao == player shuzu bianhao
                return goToTarger(collisionAvoidance(true,false,false,1.5,Target[i],true));//run to dianwei
        }
    }
    
    for(int i=0;i<6;i++){
        if((WO_TEAMMATE1+i)())
    }

    for(int i = 1;i < 5;i++){
        if(worldModel->getUNum() == i){
            target1 = VecPosition(basicPoint.getX()+(i-1)*3,basicPoint.getY()+(i-1)*4);置
            VecPosition localTarget1 = worldModel->g2l(target1);
            SIM::AngDeg localTarget1Angle = atan2Deg(localTarget1.getY(), localTarget1.getX());
            if (me.getDistanceTo(target1) < .25 && abs(localTarget1Angle) <= 10) {
                return SKILL_STAND;
            } else if (me.getDistanceTo(target1) < .5) {
                return goToTargetRelative(worldModel->g2l(target1), localTarget1Angle);
            } else {
                return goToTarget(target1);
            }
        }

    }
    if(worldModel->getGameTime() <= 70&&worldModel->getGameTime()>35){
        for(int i = 1;i<5;i++){
           if(worldModel->getUNum() == i){
            target1= VecPosition(basicPoint.getX()+5,basicPoint.getY()+(i-1)*4);
            VecPosition localTarget1 = worldModel->g2l(target1);
            SIM::AngDeg localTarget1Angle = atan2Deg(localTarget1.getY(), localTarget1.getX());
            if (me.getDistanceTo(target1) < .25 && abs(localTarget1Angle) <= 10) {
                return SKILL_STAND;
            } else if (me.getDistanceTo(target1) < .5) {
                return goToTargetRelative(worldModel->g2l(target1), localTarget1Angle);
            } else {
                return goToTarget(target1);
            }
        }  
        }
           if(worldModel->getUNum()==5){
             target1= VecPosition(2,-4.5);
            VecPosition localTarget1 = worldModel->g2l(target1);
            SIM::AngDeg localTarget1Angle = atan2Deg(localTarget1.getY(), localTarget1.getX());
            if (me.getDistanceTo(target1) < .25 && abs(localTarget1Angle) <= 10) {
                return SKILL_STAND;
            } else if (me.getDistanceTo(target1) < .5) {
                return goToTargetRelative(worldModel->g2l(target1), localTarget1Angle);
            } else {
                return goToTarget(target1);
            }
        }
         if(worldModel->getUNum()==6){
             target1= VecPosition(0,0);
            VecPosition localTarget1 = worldModel->g2l(target1);
            SIM::AngDeg localTarget1Angle = atan2Deg(localTarget1.getY(), localTarget1.getX());
            if (me.getDistanceTo(target1) < .25 && abs(localTarget1Angle) <= 10) {
                return SKILL_STAND;
            } else if (me.getDistanceTo(target1) < .5) {
                return goToTargetRelative(worldModel->g2l(target1), localTarget1Angle);
            } else {
                return goToTarget(target1);
            }
        }
    }
    if (worldModel->getUNum() == WO_TEAMMATE1 + BotForTarget[i])
         if (i == 0)
         {
             if (me.getDistanceTo(Target[0]) > 1)
                 return goToTarget(collisionAvoidance(true, false, false, 1,
                     .5, Target[0], true));
             else
             {
                 if (Posball.getX() < 9)
                 {
                     if (me.getDistanceTo(Target[1]) <
                         me.getDistanceTo(Target[2]))
                         return kickBall(KICK_FORWARD, Target[1]);
                     else
                         return kickBall(KICK_FORWARD, Target[2]);
                 }
                 else
                     return kickBall(KICK_FORWARD, VecPosition(15, 0, 0));
             }
         }
         else
             return goToTarget(collisionAvoidance(true, false, false, 1, .5,
                 Target[i], true));
    return demoKickingCircle();
}


/*
 * Demo behavior where players form a rotating circle and kick the ball
 * back and forth
 */
SkillType NaoBehavior::demoKickingCircle() {
    // Parameters for circle
    VecPosition center = VecPosition(-HALF_FIELD_X/2.0, 0, 0);
    double circleRadius = 5.0;
    double rotateRate = 2.5;

    // Find closest player to ball
    int playerClosestToBall = -1;
    double closestDistanceToBall = 10000;
    for(int i = WO_TEAMMATE1; i < WO_TEAMMATE1+NUM_AGENTS; ++i) {
        VecPosition temp;
        int playerNum = i - WO_TEAMMATE1 + 1;
        if (worldModel->getUNum() == playerNum) {
            // This is us
            temp = worldModel->getMyPosition();
        } else {
            WorldObject* teammate = worldModel->getWorldObject( i );
            if (teammate->validPosition) {
                temp = teammate->pos;
            } else {
                continue;
            }
        }
        temp.setZ(0);

        double distanceToBall = temp.getDistanceTo(ball);
        if (distanceToBall < closestDistanceToBall) {
            playerClosestToBall = playerNum;
            closestDistanceToBall = distanceToBall;
        }
    }

    if (playerClosestToBall == worldModel->getUNum()) {
        // Have closest player kick the ball toward the center
        return kickBall(KICK_FORWARD, center);
    } else {
        // Move to circle position around center and face the center
        VecPosition localCenter = worldModel->g2l(center);
        SIM::AngDeg localCenterAngle = atan2Deg(localCenter.getY(), localCenter.getX());

        // Our desired target position on the circle
        // Compute target based on uniform number, rotate rate, and time
        VecPosition target = center + VecPosition(circleRadius,0,0).rotateAboutZ(360.0/(NUM_AGENTS-1)*(worldModel->getUNum()-(worldModel->getUNum() > playerClosestToBall ? 1 : 0)) + worldModel->getTime()*rotateRate);

        // Adjust target to not be too close to teammates or the ball
        target = collisionAvoidance(true /*teammate*/, false/*opponent*/, true/*ball*/, 1/*proximity thresh*/, .5/*collision thresh*/, target, true/*keepDistance*/);

        if (me.getDistanceTo(target) < .25 && abs(localCenterAngle) <= 10) {
            // Close enough to desired position and orientation so just stand
            return SKILL_STAND;
        } else if (me.getDistanceTo(target) < .5) {
            // Close to desired position so start turning to face center
            return goToTargetRelative(worldModel->g2l(target), localCenterAngle);
        } else {
            // Move toward target location
            return goToTarget(target);
        }
    }
}


