//
//  GameModel.h
//  Tripop
//
//  Created by Bengi Mizrahi on 9/28/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "cocos2d.h"

@class Ball;
@class Hexamesh;
@class HexameshLayer;
@class SpaceLayer;
@class InfoLayer;
@class ScoresLayer;
@class LevelDirector;

@interface GameModel : Layer<NSCoding, UIAlertViewDelegate> {
    NSMutableArray* freeBalls;
    NSMutableArray* attachedBalls;
    Hexamesh* hexamesh;
    LevelDirector* levelDirector;
    
    SpaceLayer* spaceLayer;
    HexameshLayer* hexameshLayer;
    InfoLayer* infoLayer;
    ScoresLayer* scoresLayer;

    NSMutableArray* ballsJustDestroyed;
    CGFloat prevRotation;
    
    int score;
    int hiscoreBeforeThisGame;
    
    BOOL __isRunning;
}

@property (nonatomic, readonly) NSMutableArray* freeBalls;
@property (nonatomic, readonly) NSMutableArray* attachedBalls;
@property (nonatomic, readonly) Hexamesh* hexamesh;
@property (nonatomic, readonly) LevelDirector* levelDirector;

@property (nonatomic, readonly) SpaceLayer* spaceLayer;
@property (nonatomic, readonly) HexameshLayer* hexameshLayer;
@property (nonatomic, readonly) InfoLayer* infoLayer;
@property (nonatomic, readonly) ScoresLayer* scoresLayer;

@property (nonatomic, assign) BOOL __isRunning;

- (void) encodeWithCoder:(NSCoder*)aCoder;
- (id) initWithCoder:(NSCoder*)aDecoder;

- (void) startGame;
- (void) startGameWithDelay:(ccTime)aDelay;
- (void) pauseGame;
- (void) resumeGame;
- (void) resumeGameWithDelay:(ccTime)aDelay;
- (void) endGame;
- (void) step:(CGFloat)dt;
- (void) powerActionRequested;
- (void) ballsDestroyed:(NSArray*)aBalls;
- (void) addPointsToScore:(int)aPoints;

- (void) playExplosion;
- (void) playExplosionWithDelay:(ccTime)aDelay;
- (void) playPop;
- (void) playPopWithDelay:(ccTime)aDelay;
- (void) playElectric;
- (void) playCollapse;

@end
