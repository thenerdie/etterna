#ifndef GAME_CONSTANTS_AND_TYPES_H
#define GAME_CONSTANTS_AND_TYPES_H

/*
-----------------------------------------------------------------------------
 File: GameConstantsAndTypes.h

 Desc: Things that are used in many places and don't change often.

 Copyright (c) 2001-2003 by the person(s) listed below.  All rights reserved.
	Chris Danford
	Chris Gomez
-----------------------------------------------------------------------------
*/

#include "PlayerNumber.h"	// TODO: Get rid of this dependency.  -Chris

//
// Screen Dimensions
//
#define	SCREEN_WIDTH	(640)
#define	SCREEN_HEIGHT	(480)

#define	SCREEN_LEFT		(0)
#define	SCREEN_RIGHT	(SCREEN_WIDTH)
#define	SCREEN_TOP		(0)
#define	SCREEN_BOTTOM	(SCREEN_HEIGHT)

#define	CENTER_X		(SCREEN_LEFT + (SCREEN_RIGHT - SCREEN_LEFT)/2.0f)
#define	CENTER_Y		(SCREEN_TOP + (SCREEN_BOTTOM - SCREEN_TOP)/2.0f)

#define	SCREEN_NEAR		(-1000)
#define	SCREEN_FAR		(1000)

#define	ARROW_SIZE		(64)


#define FOREACH_ENUM( e, max, var )	for( e var=(e)0; var<max; ((int&)var)++ )


//
// Note definitions
//
const int MAX_METER = 12;
const int MIN_METER = 1;

/* This is just cached song data.  Not all of it may actually be displayed
 * in the radar. */
enum RadarCategory
{
	RADAR_STREAM = 0,
	RADAR_VOLTAGE,
	RADAR_AIR,
	RADAR_FREEZE,
	RADAR_CHAOS,
	RADAR_NUM_TAPS_AND_HOLDS,
	RADAR_NUM_JUMPS,
	RADAR_NUM_HOLDS,
	RADAR_NUM_MINES,
	RADAR_NUM_HANDS,
	NUM_RADAR_CATEGORIES	// leave this at the end
};
#define FOREACH_RadarCategory( rc ) FOREACH_ENUM( RadarCategory, NUM_RADAR_CATEGORIES, rc )

const CString& RadarCategoryToString( RadarCategory cat );

struct RadarValues
{
	float value[NUM_RADAR_CATEGORIES];

	RadarValues()
	{
		FOREACH_RadarCategory( rc )
			value[rc] = 0;
	}

    operator const float* () const	{ return value; };
    operator float* ()				{ return value; };

	RadarValues& operator+=( const RadarValues& other )
	{
		FOREACH_RadarCategory( rc )
			value[rc] += other.value[rc];
		return *this;
	}
};


enum Difficulty 
{
	DIFFICULTY_BEGINNER,	// corresponds to DDREX Beginner
	DIFFICULTY_EASY,		// corresponds to Basic, Easy
	DIFFICULTY_MEDIUM,		// corresponds to Trick, Another, Standard, Normal
	DIFFICULTY_HARD,		// corresponds to Maniac, SSR, Heavy, Crazy
	DIFFICULTY_CHALLENGE,	// corresponds to 5th SMANIAC, MAX2 Challenge, EX Challenge
	DIFFICULTY_EDIT,
	NUM_DIFFICULTIES,
	DIFFICULTY_INVALID
};
#define FOREACH_Difficulty( dc ) FOREACH_ENUM( Difficulty, NUM_DIFFICULTIES, dc )

const CString& DifficultyToString( Difficulty dc );
Difficulty StringToDifficulty( const CString& sDC );


enum CourseDifficulty 
{
	COURSE_DIFFICULTY_REGULAR,
	COURSE_DIFFICULTY_DIFFICULT,
	NUM_COURSE_DIFFICULTIES,
	COURSE_DIFFICULTY_INVALID
};
#define FOREACH_CourseDifficulty( cd ) FOREACH_ENUM( CourseDifficulty, NUM_COURSE_DIFFICULTIES, cd )

const CString& CourseDifficultyToString( CourseDifficulty dc );
CourseDifficulty StringToCourseDifficulty( const CString& sDC );


enum StepsType
{
	STEPS_TYPE_DANCE_SINGLE = 0,
	STEPS_TYPE_DANCE_DOUBLE,
	STEPS_TYPE_DANCE_COUPLE,
	STEPS_TYPE_DANCE_SOLO,
	STEPS_TYPE_PUMP_SINGLE,
	STEPS_TYPE_PUMP_HALFDOUBLE,
	STEPS_TYPE_PUMP_DOUBLE,
	STEPS_TYPE_PUMP_COUPLE,
	STEPS_TYPE_EZ2_SINGLE,
	STEPS_TYPE_EZ2_DOUBLE,
	STEPS_TYPE_EZ2_REAL,
	STEPS_TYPE_PARA_SINGLE,
	STEPS_TYPE_DS3DDX_SINGLE,
	STEPS_TYPE_BM_SINGLE,
    STEPS_TYPE_BM_DOUBLE,
    STEPS_TYPE_IIDX_SINGLE7,
    STEPS_TYPE_IIDX_DOUBLE7,
    // These last two are probably going to be treated the same way
	// as STEPS_TYPE_DANCE_COUPLE - autogenned for use, and then
	// a duplicate "(edit)" entry for editing only.
	STEPS_TYPE_IIDX_SINGLE5,
    STEPS_TYPE_IIDX_DOUBLE5,
    STEPS_TYPE_MANIAX_SINGLE,
	STEPS_TYPE_MANIAX_DOUBLE,
	STEPS_TYPE_TECHNO_SINGLE8,
	STEPS_TYPE_PNM_FIVE,
	STEPS_TYPE_PNM_NINE,
	NUM_STEPS_TYPES,		// leave this at the end
	STEPS_TYPE_INVALID,
};
#define FOREACH_StepsType( st ) FOREACH_ENUM( StepsType, NUM_STEPS_TYPES, st )

//
// Play mode stuff
//
enum PlayMode
{
	PLAY_MODE_ARCADE,
	PLAY_MODE_NONSTOP,	// DDR EX Nonstop
	PLAY_MODE_ONI,		// DDR EX Challenge
	PLAY_MODE_ENDLESS,	// DDR PlayStation Endless
	PLAY_MODE_BATTLE,	// manually launched attacks
	PLAY_MODE_RAVE,		// automatically launched attacks - DDR Disney Rave "Dance Magic"
	NUM_PLAY_MODES,
	PLAY_MODE_INVALID
};
#define FOREACH_PlayMode( pm ) FOREACH_ENUM( PlayMode, NUM_PLAY_MODES, pm )

const CString& PlayModeToString( PlayMode pm );
PlayMode StringToPlayMode( const CString& s );




enum SortOrder {
	SORT_PREFERRED,
	SORT_GROUP, 
	SORT_TITLE, 
	SORT_BPM, 
	SORT_MOST_PLAYED, 
	SORT_GRADE,
	SORT_ARTIST,
	SORT_EASY_METER,
	SORT_MEDIUM_METER,
	SORT_HARD_METER,
	SORT_CHALLENGE_METER,
	SORT_SORT_MENU,
	SORT_MODE_MENU,
	SORT_ALL_COURSES,
	SORT_NONSTOP_COURSES,
	SORT_ONI_COURSES,
	SORT_ENDLESS_COURSES,
	SORT_ROULETTE,
	NUM_SORT_ORDERS,
	SORT_INVALID
};
const SortOrder MAX_SELECTABLE_SORT = (SortOrder)(SORT_ROULETTE-1);

#define FOREACH_SortOrder( so ) FOREACH_ENUM( SortOrder, NUM_SORT_ORDERS, so )

const CString& SortOrderToString( SortOrder so );
SortOrder StringToSortOrder( const CString& str );

inline bool IsSongSort( SortOrder so ) { return so >= SORT_PREFERRED && so <= SORT_CHALLENGE_METER; }

//
// Scoring stuff
//

enum TapNoteScore { 
	TNS_NONE, 
	TNS_HIT_MINE,
	TNS_MISS,
	TNS_BOO,
	TNS_GOOD,
	TNS_GREAT,
	TNS_PERFECT,
	TNS_MARVELOUS,
	NUM_TAP_NOTE_SCORES
};
#define FOREACH_TapNoteScore( tns ) FOREACH_ENUM( TapNoteScore, NUM_TAP_NOTE_SCORES, tns )

const CString& TapNoteScoreToString( TapNoteScore tns );

//enum TapNoteTiming { 
//	TNT_NONE, 
//	TNT_EARLY, 
//	TNT_LATE 
//};


enum HoldNoteScore 
{ 
	HNS_NONE,	// this HoldNote has not been scored yet
	HNS_OK,		// the HoldNote has passed and was successfully held all the way through
	HNS_NG,		// the HoldNote has passed and they missed it
	NUM_HOLD_NOTE_SCORES
};
#define FOREACH_HoldNoteScore( hns ) FOREACH_ENUM( HoldNoteScore, NUM_HOLD_NOTE_SCORES, hns )


//
// Profile and MemCard stuff
//
enum ProfileSlot
{
	PROFILE_SLOT_PLAYER_1,
	PROFILE_SLOT_PLAYER_2,
	PROFILE_SLOT_MACHINE,
	NUM_PROFILE_SLOTS,
	PROFILE_SLOT_INVALID
};
#define FOREACH_ProfileSlot( slot ) FOREACH_ENUM( ProfileSlot, NUM_PROFILE_SLOTS, slot )


enum MemoryCardState
{ 
	MEMORY_CARD_STATE_READY, 
	MEMORY_CARD_STATE_TOO_LATE, 
	MEMORY_CARD_STATE_WRITE_ERROR, 
	MEMORY_CARD_STATE_NO_CARD,
	NUM_MEMORY_CARD_STATES,
	MEMORY_CARD_STATE_INVALID,
};

const CString& MemoryCardStateToString( MemoryCardState mcs );


//
// Ranking stuff
//
enum RankingCategory
{
	RANKING_A,	// 1-3 meter per song avg.
	RANKING_B,	// 4-6 meter per song avg.
	RANKING_C,	// 7-9 meter per song avg.
	RANKING_D,	// 10+ meter per song avg.	// doesn't count extra stage!
	NUM_RANKING_CATEGORIES,
	RANKING_INVALID
};
#define FOREACH_RankingCategory( rc ) FOREACH_ENUM( RankingCategory, NUM_RANKING_CATEGORIES, rc )
const CString& RankingCategoryToString( RankingCategory rc );
RankingCategory StringToRankingCategory( const CString& rc );

const CString RANKING_TO_FILL_IN_MARKER[NUM_PLAYERS] = {"#P1#","#P2#"};
inline bool IsRankingToFillIn( const CString& sName ) { return !sName.empty() && sName[0]=='#'; }

RankingCategory AverageMeterToRankingCategory( float fAverageMeter );

const int NUM_RANKING_LINES	= 5;


//
// Group stuff
//
#define GROUP_ALL_MUSIC	CString("")


//
//
//
enum PlayerController
{
	PC_HUMAN,
	PC_CPU,
	PC_AUTOPLAY,
	NUM_PLAYER_CONTROLLERS
};

const int MIN_SKILL = 0;
const int MAX_SKILL = 10;


enum StageResult
{
	RESULT_WIN,
	RESULT_LOSE,
	RESULT_DRAW
};


//
// Battle stuff
//
const int NUM_INVENTORY_SLOTS	= 3;
enum AttackLevel
{
	ATTACK_LEVEL_1,
	ATTACK_LEVEL_2,
	ATTACK_LEVEL_3,
	NUM_ATTACK_LEVELS
};
const int NUM_ATTACKS_PER_LEVEL	= 3;
const int ITEM_NONE = -1;


#define BG_ANIMS_DIR		CString("BGAnimations/")
#define VISUALIZATIONS_DIR	CString("Visualizations/")
#define RANDOMMOVIES_DIR	CString("RandomMovies/")



//
// Coin stuff
//

enum CoinMode { COIN_HOME, COIN_PAY, COIN_FREE, NUM_COIN_MODES };

const CString& CoinModeToString( CoinMode cm );


//
// Award stuff
//

enum PerDifficultyAward
{
	AWARD_FULL_COMBO_GREATS,
	AWARD_FULL_COMBO_PERFECTS,
	AWARD_FULL_COMBO_MARVELOUSES,
	AWARD_SINGLE_DIGIT_GREATS,
	AWARD_SINGLE_DIGIT_PERFECTS,
	AWARD_GREATS_80_PERCENT,
	AWARD_GREATS_90_PERCENT,
	AWARD_GREATS_100_PERCENT,
	NUM_PER_DIFFICULTY_AWARDS,
	PER_DIFFICULTY_AWARD_INVALID,
};
#define FOREACH_PerDifficultyAward( pma ) FOREACH_ENUM( PerDifficultyAward, NUM_PER_DIFFICULTY_AWARDS, pma )
const CString& PerDifficultyAwardToString( PerDifficultyAward pma );
CString PerDifficultyAwardToThemedString( PerDifficultyAward pma );
PerDifficultyAward StringToPerDifficultyAward( const CString& pma );


enum PeakComboAward 
{ 
	AWARD_1000_PEAK_COMBO,
	AWARD_2000_PEAK_COMBO,
	AWARD_3000_PEAK_COMBO,
	AWARD_4000_PEAK_COMBO,
	AWARD_5000_PEAK_COMBO,
	AWARD_6000_PEAK_COMBO,
	AWARD_7000_PEAK_COMBO,
	AWARD_8000_PEAK_COMBO,
	AWARD_9000_PEAK_COMBO,
	AWARD_10000_PEAK_COMBO,
	NUM_PEAK_COMBO_AWARDS,
	PEAK_COMBO_AWARD_INVALID,
};
#define FOREACH_PeakComboAward( pca ) FOREACH_ENUM( PeakComboAward, NUM_PEAK_COMBO_AWARDS, pca )
const CString& PeakComboAwardToString( PeakComboAward pma );
CString PeakComboAwardToThemedString( PeakComboAward pma );
PeakComboAward StringToPeakComboAward( const CString& pma );


#endif
