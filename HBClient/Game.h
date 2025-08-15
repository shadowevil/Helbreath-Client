// Game.h: interface for the CGame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAME_H__0089D9E3_74E6_11D2_A8E6_00001C7030A6__INCLUDED_)
#define AFX_GAME_H__0089D9E3_74E6_11D2_A8E6_00001C7030A6__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <mmsystem.h> 
#include <winbase.h>
#include <memory.h>
#include <string.h>
#include <process.h>
#include <direct.h>
#include "GlobalDef.h"
#include "DXC_ddraw.h"
#include "DXC_dinput.h"
#include "YWSound.h"
#include "SoundBuffer.h"
#ifdef DEF_HTMLCOMMOM
	#include "stdafx.h"
#endif
#include "XSocket.h"
#include "Sprite.h"
#include "SpriteID.h"
#include "Misc.h"
#include "StrTok.h"
#include "Msg.h"
#include "Effect.h"
#include "MapData.h"
#include "ActionID.h"
#include "NetMessages.h"
#include "MouseInterface.h"
#include "CharInfo.h"
#include "Item.h"
#include "Magic.h"
#include "Skill.h"
#include "DynamicObjectID.h"
#include "GameMonitor.h"
#include "BuildItem.h"
#include "ItemName.h"
#include "Curse.h"
#include "CInt\Cint.h"
#ifdef DEF_USING_WIN_IME
#include <RICHEDIT.H>
#endif

//v2.18
#define DEF_BTNSZX				74
#define DEF_BTNSZY				20
#define DEF_LBTNPOSX			30
#define DEF_RBTNPOSX			154
#define DEF_BTNPOSY				292

#define DEF_INDEX4_MSGID		0
#define DEF_INDEX2_MSGTYPE		4

#define DEF_SOCKETBLOCKLIMIT	300

#define DEF_MAXSPRITES			20000
#define DEF_MAXTILES			500
#define DEF_MAXEFFECTSPR		100
#define DEF_MAXSOUNDEFFECTS		110   //������ ����, ���� 100.
#define DEF_MAXCHATMSGS			500
#define DEF_MAXWHISPERMSG		5
#define DEF_MAXCHATSCROLLMSGS	80
#define DEF_MAXEFFECTS			300	//600 <- original
#define DEF_CHATTIMEOUT_A		4000
#define DEF_CHATTIMEOUT_B		500
#define DEF_CHATTIMEOUT_C		2000
#define DEF_MAXITEMS			50
#define DEF_MAXBANKITEMS		121 // v1.2 120+1	
#define DEF_MAXGUILDSMAN		32
#define DEF_MAXMENUITEMS		140  //v2.15  120 ->140
#define DEF_TEXTDLGMAXLINES		300 //v2.18 3000->300

#define DEF_MAXMAGICTYPE		100
#define DEF_MAXSKILLTYPE		60

#define DEF_MAXWHETHEROBJECTS	600
#define DEF_MAXBUILDITEMS		100

#define DEF_MAXGAMEMSGS			300
#define DEF_MAXITEMNAMES		1000

// v2.171 2002-6-14
#define DEF_MAXGUILDNAMES		100

// v2.174 2002-7-19 �Ȼ���
#define DEF_MAXSELLLIST			12

#define WM_USER_GAMESOCKETEVENT	WM_USER + 2000
#define WM_USER_LOGSOCKETEVENT	WM_USER + 2001

#define DEF_GAMEMODE_NULL					-2
#define DEF_GAMEMODE_ONQUIT					-1
#define DEF_GAMEMODE_ONMAINMENU				0
#define DEF_GAMEMODE_ONCONNECTING			1
#define DEF_GAMEMODE_ONLOADING				2
#define DEF_GAMEMODE_ONWAITINGINITDATA		3
#define DEF_GAMEMODE_ONMAINGAME				4
#define DEF_GAMEMODE_ONCONNECTIONLOST		5
#define DEF_GAMEMODE_ONMSG					6
#define DEF_GAMEMODE_ONCREATENEWACCOUNT		7
#define DEF_GAMEMODE_ONLOGIN				8
#define DEF_GAMEMODE_ONQUERYFORCELOGIN		9
#define DEF_GAMEMODE_ONSELECTCHARACTER		10
#define DEF_GAMEMODE_ONCREATENEWCHARACTER	11
#define DEF_GAMEMODE_ONWAITINGRESPONSE		12
#define DEF_GAMEMODE_ONQUERYDELETECHARACTER 13
#define DEF_GAMEMODE_ONLOGRESMSG			14
#define DEF_GAMEMODE_ONCHANGEPASSWORD		15
#define DEF_GAMEMODE_ONVERSIONNOTMATCH		17
#define DEF_GAMEMODE_ONINTRODUCTION			18
#define DEF_GAMEMODE_ONAGREEMENT			19
#define DEF_GAMEMODE_ONSELECTSERVER			20
#define DEF_GAMEMODE_ONINPUTKEYCODE			21

#define DEF_SERVERTYPE_GAME			1
#define DEF_SERVERTYPE_LOG			2

#define DEF_CURSORSTATUS_NULL		0
#define DEF_CURSORSTATUS_PRESSED	1
#define DEF_CURSORSTATUS_SELECTED	2
#define DEF_CURSORSTATUS_DRAGGING	3

#define DEF_SELECTEDOBJTYPE_DLGBOX	1
#define DEF_SELECTEDOBJTYPE_ITEM	2

#define DEF_DOUBLECLICKTIME			300
#define DEF_MAXPARTYMEMBERS			8
#define DEF_MAXCRUSADESTRUCTURES	300

class CGame  
{
public:
	int m_iTeleportMapCount;
	void ResponseTeleportList(const char* pData);
	void ResponseChargedTeleport(const char* pData);
	void * operator new (size_t size) 
	{
		return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);	
	};
	
	void operator delete(void * mem)
	{
		HeapFree(GetProcessHeap(), HEAP_NO_SERIALIZE, mem); 		
	};

	void ItemEquipHandler(char cItemID);
	void ReleaseEquipHandler(char cEquipPos);

	void ReadSettings();//�������� �����Ѱ� �о���� ��ƾ.
	void WriteSettings();

	int  iGetManaCost(int iMagicNo);
	void UseMagic(int iMagicNo);
	BOOL _bCheckMoveable( short sx, short sy );
	BOOL FindGuildName(const char* pName, int* ipIndex);
	void bItemDrop_SkillDialog();
	void bItemDrop_IconPannel(short msX, short msY);
	void bItemDrop_Character();
	void bItemDrop_Inventory(short msX, short msY);
	void bItemDrop_ItemUpgrade();
	void bItemDrop_SellList(short msX, short msY);
	void bItemDrop_ExchangeDialog(short msX, short msY);
	void bItemDrop_Bank(short msX, short msY);
	void bItemDrop_ExternalScreen(char cItemID, short msX, short msY);
	void CreateScreenShot();
	void CrusadeWarResult(int iWinnerSide);
	void CrusadeContributionResult(int iWarContribution);
	void CannotConstruct(int iCode);
	void DrawTopMsg();
	void SetTopMsg(const char* pString, unsigned char iLastSec);
	void DrawObjectFOE(int ix, int iy, int iFrame);
	void GrandMagicResult(const char* pMapName, int iV1, int iV2, int iV3, int iV4, int iHP1, int iHP2, int iHP3, int iHP4) ;
	void MeteorStrikeComing(int iCode);
	void _Draw_OnLogin(const char* pAccount, const char* pPassword, int msX, int msY, int iFrame = 60000);
	void DrawNewDialogBox(char cType, int sX, int sY, int iFrame, BOOL bIsNoColorKey = FALSE, BOOL bIsTrans = FALSE);
	void AddMapStatusInfo(char* pData, BOOL bIsLastData);
	void _RequestMapStatus(const char* pMapName, int iMode);
	int  GetCharKind(const char*str, int index);
	void ReceiveString(char* pString);
	void EndInputString();
	void ClearInputString();
	void ShowReceivedString(BOOL bIsHide = FALSE);
	bool GetText(HWND hWnd,UINT msg,WPARAM wparam, LPARAM lparam);
	BOOL bReadItemNameConfigFile();
	void DrawDialogBoxs(short msX, short msY, short msZ, char cLB);
	void DrawDialogBox_Character(short msX, short msY);//1
	void DrawDialogBox_Inventory(int msX, int msY);//2
	void DrawDialogBox_Magic(short msX, short msY, short msZ);//3
	void DrawDialogBox_GuildMenu(short msX, short msY);//7
	void DrawDialogBox_GuildOperation(short msX, short msY);//8
	void DrawDialogBox_GuideMap(short msX, short msY, char cLB);//9
	void DrawDialogBox_Chat(short msX, short msY, short msZ, char cLB);//10
	void DrawDialogBox_Shop(short msX, short msY, short msZ, char cLB);//11
	void DrawDialogBox_LevelUpSetting(short msX, short msY);//12
	void DrawDialogBox_CityHallMenu(short msX, short msY);//13
	void DrawDialogBox_Bank(short msX, short msY, short msZ, char cLB);//14
	void DrawDialogBox_Skill(short msX, short msY, short msZ, char cLB);//15
	void DrawDialogBox_MagicShop(short msX, short msY, short msZ);//16
	void DrawDialogBox_QueryDropItemAmount();//17
	void DrawDialogBox_Text(short msX, short msY, short msZ, char cLB);//18
	void DrawDialogBox_SysMenu(short msX, short msY, char cLB);//19
	void DrawDialogBox_NpcActionQuery(short msX, short msY);//20
	void DrawDialogBox_NpcTalk(short msX, short msY, char cLB);//21
	void DrawDialogBox_Map();//22
	void DrawDialogBox_SellorRepairItem(short msX, short msY);//23
	void DrawDialogBox_Fishing(short msX, short msY);//24
	void DrawDialogBox_ShutDownMsg(short msX, short msY);//25
	void DrawDialogBox_SkillDlg(short msX, short msY, short msZ, char cLB);//26
	void DrawDialogBox_Exchange(short msX, short msY);//27
	void DrawDialogBox_Quest(int msX, int msY);//28
	void DrawDialogBox_GaugePannel();//29
	void DrawDialogBox_IconPannel(short msX, short msY);//30
	void DrawDialogBox_SellList(short msX, short msY);//31
	void DrawDialogBox_Party(short msX, short msY);//32
	void DrawDialogBox_CrusadeJob(short msX, short msY);//33
	void DrawDialogBox_ItemUpgrade(int msX, int msY);//34
	void DrawDialogBox_Help(int msX, int msY);//35
	void DrawDialogBox_Commander(int msX, int msY);//36
	void DrawDialogBox_Constructor(int msX, int msY);//37
	void DrawDialogBox_Soldier(int msX, int msY);//38
    void DrawDialogBox_ItemDrop(short msX, short msY);//4 ������.
	void DrawDialogBox_WarningMsg(short msX, short msY);//6 ������.
	void DrawDialogBox_15AgeMsg(short msX, short msY);//5 ������.
	void DrawDialogBox_FeedBackCard(short msX, short msY);//40 ������.
	void DisplayGold(int iGold);//5 ������.

	BOOL _bCheckDlgBoxClick(short msX, short msY);
	void DlgBoxClick_WarningMsg(short msX, short msY);
	void DlgBoxClick_15AgeMsg(short msX, short msY);// ������.
	void DlgBoxClick_ItemDrop(short msX, short msY);// ������.
	void DlgBoxClick_Character(short msX, short msY);
	void DlgBoxClick_Inventory(short msX, short msY);
	void DlgBoxClick_Magic(short msX, short msY);
	void DlgBoxClick_GuildMenu(short msX, short msY);
	void DlgBoxClick_GuildOp(short msX, short msY);
	void DlgBoxClick_Shop(short msX, short msY);
	void DlgBoxClick_LevelUpSettings(short msX, short msY);
	void DlgBoxClick_CityhallMenu(short msX, short msY);
	void DlgBoxClick_Bank(short msX, short msY);
	void DlgBoxClick_Skill(short msX, short msY);
	void DlgBoxClick_MagicShop(short msX, short msY);
	void DlgBoxClick_FeedBackCard(short msX, short msY);
	void DlgBoxClick_Text(short msX, short msY);
	void DlgBoxClick_SysMenu(short msX, short msY);
	void DlgBoxClick_NpcActionQuery(short msX, short msY);
	void DlgBoxClick_NpcTalk(int msX, int msY);
	void DlgBoxClick_ItemSellorRepair(short msX, short msY);
	void DlgBoxClick_Fish(short msX, short msY);
	void DlgBoxClick_ShutDownMsg(short msX, short msY);
	void DlgBoxClick_SkillDlg(short msX, short msY);
	void DlgBoxClick_Exchange(short msX, short msY);
	void DlgBoxClick_Quest(int msX, int msY);
	void DlgBoxClick_SellList(short msX, short msY);
	void DlgBoxClick_IconPannel(short msX, short msY);
	void DlgBoxClick_Party(short msX, short msY);
	void DlgBoxClick_CrusadeJob(short msX, short msY);
	void DlgBoxClick_ItemUpgrade(int msX, int msY);
	void DlgBoxClick_Help(int msX, int msY);
	void DlgBoxClick_Commander(int msX, int msY);
	void DlgBoxClick_Constructor(int msX, int msY);
	void DlgBoxClick_Soldier(int msX, int msY);
	void NotifyMsgHandler(char* pData);
	void NotifyMsg_GlobalAttackMode(const char* pData);
	void NotifyMsg_QuestReward(const char* pData);
	void NotifyMsg_QuestContents(const char* pData);
	void NotifyMsg_ItemColorChange(const char* pData);
	void NotifyMsg_DropItemFin_CountChanged(const char* pData);
	void NotifyMsg_CannotGiveItem(const char* pData);
	void NotifyMsg_GiveItemFin_CountChanged(const char* pData);
	void NotifyMsg_SetExchangeItem(const char* pData);
	void NotifyMsg_OpenExchageWindow(const char* pData);
	void NotifyMsg_DownSkillIndexSet(const char* pData);
	void NotifyMsg_AdminInfo(const char* pData);
	void NotifyMsg_WhetherChange(const char* pData);
	void NotifyMsg_FishChance(const char* pData);
	void NotifyMsg_EventFishMode(const char* pData);
	void NotifyMsg_NoticeMsg(const char* pData);
	void NotifyMsg_RatingPlayer(const char* pData);
	void NotifyMsg_CannotRating(const char* pData);
	void NotifyMsg_PlayerShutUp(const char* pData);
	void NotifyMsg_TimeChange(const char* pData);
	void NotifyMsg_Hunger(const char* pData);
	void NotifyMsg_PlayerProfile(const char* pData);
	void NotifyMsg_WhisperMode(BOOL bActive, const char* pData);
	void NotifyMsg_PlayerStatus(BOOL bOnGame, const char* pData);
	void NotifyMsg_Charisma(const char* pData);
	void NotifyMsg_ItemRepaired(const char* pData);
	void NotifyMsg_RepairItemPrice(const char* pData);
	void NotifyMsg_CannotRepairItem(const char* pData);
	void NotifyMsg_CannotSellItem(const char* pData);
	void NotifyMsg_SellItemPrice(const char* pData);
	void NotifyMsg_ShowMap(const char* pData);
	void NotifyMsg_SkillUsingEnd(const char* pData);
	void NotifyMsg_TotalUsers(const char* pData);
	void NotifyMsg_MagicEffectOff(const char* pData); 
	void NotifyMsg_MagicEffectOn(const char* pData);
	void NotifyMsg_SetItemCount(const char* pData);
	void NotifyMsg_ItemDepleted_EraseItem(const char* pData);
	void NotifyMsg_ServerChange(const char* pData);
	void NotifyMsg_Skill(const char* pData);
	void NotifyMsg_DropItemFin_EraseItem(const char* pData);
	void NotifyMsg_GiveItemFin_EraseItem(const char* pData);
	void NotifyMsg_EnemyKillReward(const char* pData);
	void NotifyMsg_PKcaptured(const char* pData);
	void NotifyMsg_PKpenalty(const char* pData);
	void NotifyMsg_ItemToBank(char* pData);
	void NotifyMsg_ItemLifeSpanEnd(const char* pData);
	void NotifyMsg_ItemReleased(const char* pData);
	void NotifyMsg_LevelUp(const char* pData);
	void NotifyMsg_MP(const char* pData);
	void NotifyMsg_SP(const char* pData);
	void NotifyMsg_SkillTrainSuccess(const char* pData);
	void NotifyMsg_MagicStudyFail(const char* pData);
	void NotifyMsg_MagicStudySuccess(const char* pData);
	void NotifyMsg_DismissGuildsMan(const char* pData);
	void NotifyMsg_NewGuildsMan(const char* pData);
	void NotifyMsg_CannotJoinMoreGuildsMan(const char* pData);
	void NotifyMsg_GuildDisbanded(const char* pData);
	void NotifyMsg_Exp(const char* pData);
	void NotifyMsg_Killed(const char* pData);
	void NotifyMsg_HP(const char* pData);
	void NotifyMsg_ItemPurchased(const char* pData);
	void NotifyMsg_DismissGuildReject(const char* pData);
	void NotifyMsg_DismissGuildApprove(const char* pData);
	void NotifyMsg_JoinGuildReject(const char* pData);
	void NotifyMsg_JoinGuildApprove(const char* pData);
	void NotifyMsg_QueryDismissGuildPermission(const char* pData);
	void NotifyMsg_QueryJoinGuildPermission(const char* pData);
	void NotifyMsg_ItemObtained(const char* pData);
	void NotifyMsg_ForceDisconn(const char* pData);
	void NotifyMsg_BanGuildMan(const char* pData);

	void ResponsePanningHandler(const char* pData);
	void _CalcSocketClosed();
	void UpdateScreen_OnSelectServer();
	void StartInputString(int sX, int sY, unsigned char iLen, char* pBuffer, BOOL bIsHide = FALSE);
	void _SetIlusionEffect(int iOwnerH);
	int _iGetFOE(short sStatus);
	void NoticementHandler(const char* pData);
	void GetItemName(const char* cItemName, DWORD dwAttribute, char*pStr1, char*pStr2, char*pStr3);
	void GetItemName(class CItem * pItem, char* pStr1, char* pStr2, char* pStr3);
	void _InitOnCreateNewCharacter();
	void _LoadGameMsgTextContents();
	BOOL _bCheckCurrentBuildItemStatus();
	BOOL _bCheckBuildItemStatus();
	BOOL _bDecodeBuildItemContents();
	int  _iCheckLUS();
	BOOL _bCheckBadWords(const char* pMsg);
	void GetNpcName(short sType, char* pName);
#ifdef DEF_MAKE_ACCOUNT
	int m_iAgreeView;
	void _LoadAgreementTextContents(char cType);
	void UpdateScreen_OnAgreement();
	void UpdateScreen_OnCreateNewAccount();
#endif
#if DEF_LANGUAGE == 2
	void UpdateScreen_OnInputKeyCode();
#endif
	void UseShortCut( int num );
	void UpdateScreen();
	void UpdateScreen_OnMainMenu();
	void UpdateScreen_OnGame();
	void UpdateScreen_OnConnecting();
	void UpdateScreen_OnWaitInitData();
	void MakeSprite(const char* FileName, short sStart, short sCount, bool bAlphaEffect = TRUE);
	void MakeTileSpr(const  char* FileName, short sStart, short sCount, bool bAlphaEffect = TRUE);
	void MakeEffectSpr(const char* FileName, short sStart, short sCount, bool bAlphaEffect = TRUE);
	void UpdateScreen_OnLoading(bool bActive);
	void UpdateScreen_OnConnectionLost();
	void UpdateScreen_OnLogin();
	void UpdateScreen_OnMsg();
	void UpdateScreen_OnQuit();
	void UpdateScreen_OnQueryForceLogin();
	void UpdateScreen_OnQueryDeleteCharacter();
	void UpdateScreen_OnWaitingResponse();
	void UpdateScreen_OnCreateNewCharacter();
	void UpdateScreen_OnSelectCharacter();
	void UpdateScreen_OnLogResMsg();
	void UpdateScreen_OnSelectCharacter(short sX, short sY, short msX, short msY, BOOL bIgnoreFocus = FALSE);
	void UpdateScreen_OnChangePassword();
	void UpdateScreen_OnLoading_Progress();
	void UpdateScreen_OnVersionNotMatch();
	void NpcTalkHandler(const char* pData);
	int  _iGetWeaponSkillType();
	void SetCameraShakingEffect(short sDist, int iMul = 0);
	BOOL bDlgBoxPress_SkillDlg(short msX, short msY);
	BOOL bDlgBoxPress_Inventory(short msX, short msY);
	BOOL bDlgBoxPress_Character(short msX, short msY);
	void ClearSkillUsingStatus();
	BOOL bCheckItemOperationEnabled(char cItemID);
	void _DrawThunderEffect(int sX, int sY, int dX, int dY, int rX, int rY, char cType);
	void DrawLine2(int x0, int y0, int x1, int y1, int iR, int iG, int iB);
	void DrawLine(int x0, int y0, int x1, int y1, int iR, int iG, int iB);
	void SetWhetherStatus(BOOL bStart, char cType);
	void WhetherObjectFrameCounter();
	void DrawWhetherEffects();
	BOOL bCheckExID(const char* pName);
	BOOL bCheckLocalChatCommand(const char* pMsg);
	char GetOfficialMapName(char* pMapName, char* pName);
	int iGetLevelExp(int iLevel);
	int _iCalcTotalWeight();
	void DrawVersion();
	BOOL _bIsItemOnHand();
	void DynamicObjectHandler(const char* pData);
	BOOL _bCheckItemByType(char cType);
	void _DrawBlackRect(int iSize);
	void DrawNpcName(   short sX, short sY, short sOwnerType, short sStatus);
	void DrawObjectName(short sX, short sY, const char* pName, short sStatus);
	void PlaySound(char cType, int iNum, int iDist, long lPan = 0);
	void _RemoveChatMsgListByObjectID(int iObjectID);
	void _LoadTextDlgContents(int cType);
	int  _iLoadTextDlgContents2(int iType);
	void DrawChatMsgs(short sX, short sY, short dX, short dY);
	void RequestFullObjectData(WORD wObjectID);
	BOOL bInitSkillCfgList();
	BOOL bCheckImportantFile();
	void DlbBoxDoubleClick_Inventory(short msX, short msY);
	void DlbBoxDoubleClick_Character(short msX, short msY);
	void DlbBoxDoubleClick_GuideMap(short msX, short msY);
	BOOL _bCheckDlgBoxDoubleClick(short msX, short msY);
	void EraseItem(char cItemID);
	void RetrieveItemHandler(const char* pData);
	void CivilRightAdmissionHandler(const char* pData);
	void _Draw_CharacterBody(short sX, short sY, short sType);
	void ClearContents_OnSelectCharacter();
	void ClearContents_OnCreateNewAccount();
	void _Draw_UpdateScreen_OnCreateNewAccount();
	BOOL _bDraw_OnCreateNewCharacter(const char* pName, short msX, short msY, int iPoint);
	BOOL _bGetIsStringIsNumber(const char* pStr);
	BOOL bInitMagicCfgList();
	BOOL __bDecodeContentsAndBuildItemForSaleList(const char* pBuffer);
	void _LoadShopMenuContents(char cType);
	void PutChatScrollList(char* pMsg, char cType);
	void RequestTeleportAndWaitData();
	void DrawEffectLights();
	void PointCommandHandler(int indexX, int indexY, char cItemID = -1);
	void DrawEffects();
	void bAddNewEffect(short sType, int sX, int sY, int dX, int dY, char cStartFrame, int iV1 = 1);
	void AddEventList(const char* pTxt, char cColor = 0, BOOL bDupAllow = TRUE);
	void ShowEventList(DWORD dwTime);
	void SetItemCount(const char* pItemName, DWORD dwCount);
	void _ShiftGuildOperationList();
	void _PutGuildOperationList(const char* pName, char cOpMode);
	void DisbandGuildResponseHandler(const char* pData);
	void InitPlayerCharacteristics(const char* pData);
	void CreateNewGuildResponseHandler(const char* pData);
	void _GetHairColorRGB(int iColorType , int * pR, int * pG, int * pB); 
	void InitGameSettings();
	void CommonEventHandler(const char* pData);
	BOOL _bCheckDraggingItemRelease(short msX, short msY);
	void _SetItemOrder(char cWhere, char cItemID);
	int iGetTopDialogBoxIndex();
	void DisableDialogBox(int iBoxID);
	void EnableDialogBox(int iBoxID, int cType, int sV1, int sV2, const char* pString = NULL);
	void InitItemList(const char* pData);
	int _iCheckDlgBoxFocus(short msX, short msY, char cButtonSide);
	void GetPlayerTurn(); 
	BOOL __fastcall DrawObject_OnDead(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnDying(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnMagic(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnAttack(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnAttackMove(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnStop(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnMove_ForMenu(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnMove(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnDamageMove(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnRun(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnDamage(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL __fastcall DrawObject_OnGetItem(int indexX, int indexY, int sX, int sY, BOOL bTrans, DWORD dwTime, int msX, int msY);
	BOOL bEffectFrameCounter();
	void ClearGuildNameList();
	void DrawBackground(short sDivX, short sModX, short sDivY, short sModY);
	void DrawChatMsgBox(short sX, short sY, int iChatIndex, BOOL bIsPreDC);
	void ReleaseTimeoverChatMsg();
	void ChatMsgHandler(const char* pData);
	void ReleaseUnusedSprites();
	BOOL bReadLoginConfigFile(const char* cFn);
	void OnKeyUp(WPARAM wParam);
	void OnSysKeyDown(WPARAM wParam);
	void OnSysKeyUp(WPARAM wParam);
	void ChangeGameMode(char cMode);
	void PutString(int iX, int iY, const char* pString, COLORREF color);
	void PutString(int iX, int iY, const char* pString, COLORREF color, BOOL bHide, char cBGtype, BOOL bIsPreDC = FALSE);
	void PutString2(int iX, int iY, const char* pString, short sR, short sG, short sB);
	void PutAlignedString(int iX1, int iX2, int iY, const char* pString, short sR = 0, short sG = 0, short sB = 0);
	void PutString_SprFont(int iX, int iY, const char* pStr, short sR, short sG, short sB);
	void PutString_SprFont2(int iX, int iY, const char* pStr, short sR, short sG, short sB);
	void PutString_SprFont3(int iX, int iY, const char* pStr, short sR, short sG, short sB, BOOL bTrans = FALSE, int iType = 0);
	void PutString_SprNum(int iX, int iY, const char* pStr, short sR, short sG, short sB);
	void LogRecvMsgHandler(char* pData);
	void LogResponseHandler(char* pData);
	void OnLogSocketEvent(WPARAM wParam, LPARAM lParam);
	void OnTimer();
	void LogEventHandler(const char* pData);
	void _ReadMapData(short sPivotX, short sPivotY, char* pData);
	void MotionEventHandler(const char* pData);
	void InitDataResponseHandler(const char* pData);
	void InitPlayerResponseHandler(const char* pData);
	void ConnectionEstablishHandler(char cWhere);
	void MotionResponseHandler(const char* pData);
	void GameRecvMsgHandler(DWORD dwMsgSize, char* pData);
	void DrawObjects(short sPivotX, short sPivotY, short sDivX, short sDivY, short sModX, short sModY, short msX, short msY);
	BOOL bSendCommand(DWORD dwMsgID, WORD wCommand, char cDir, int iV1, int iV2, int iV3, const char* pString, int iV4 = NULL); // v1.4
	char cGetNextMoveDir(short sX, short sY, short dstX, short dstY, BOOL bMoveCheck = FALSE);
	void RestoreSprites();
	void CommandProcessor(short msX, short msY, short indexX, short indexY, char cLB, char cRB);
	void OnGameSocketEvent(WPARAM wParam, LPARAM lParam);
	void CalcViewPoint();
	void OnKeyDown(WPARAM wParam);
	void Quit();
	BOOL bInit(HWND hWnd, HINSTANCE hInst, const char* pCmdLine);
	// v1.4311-3 �Լ� ���� ���� ��� �߹�Ǵ� ��� �޼��� 
	// v1.4311-3 ���� ������ ���࿡ ���� ����
	void ReserveFightzoneResponseHandler(const char* pData);
	int _iGetAttackType();
	BOOL __bDecodeBuildItemContents(const char* pBuffer);
	int _iGetBankItemCount();
	int _iGetTotalItemNum();
	LONG GetRegKey(HKEY key, LPCTSTR subkey, LPTSTR retdata);
	void GoHomepage();
	void StartBGM();

	//2002. 10. 29 ������ ������ ������...
	BOOL _ItemDropHistory(const char* ItemName);

	CGame();
	virtual ~CGame();

	struct {
		// ���콺 Ŀ���� ��� ����� �����̽� 
		short sX;
		short sY;
		short sCursorFrame;
		// ���콺 Ŀ���� ����
		char  cPrevStatus;
		char  cSelectedObjectType;
		short sSelectedObjectID;
		short sPrevX, sPrevY, sDistX, sDistY;
		DWORD dwSelectClickTime;
		short sClickX, sClickY;
	} m_stMCursor;

	struct {
		int   sV1, sV2, sV3, sV4, sV5, sV6, sV7, sV8, sV9, sV10, sV11, sV12, sV13, sV14; // v1.4 short
		DWORD dwV1, dwV2, dwT1;
		BOOL  bFlag;
		short sX, sY;
		short sSizeX, sSizeY;
		short sView;
		char  cStr[32], cStr2[32], cStr3[32], cStr4[32];
		char  cMode;
		BOOL  bIsScrollSelected;
	} m_stDialogBoxInfo[41];

	struct {
		int iIndex;
		int iAmount;
	} m_stSellItemList[DEF_MAXSELLLIST];

	struct {
		char cName[22];
		char cOpMode;
	} m_stGuildOpList[100];

	struct {
		DWORD dwTime;
		char  cColor;
		char  cTxt[96];
	} m_stEventHistory[6];

	struct {
		DWORD dwTime;
		char  cColor;
		char  cTxt[96];
	} m_stEventHistory2[6];

	struct {
		short sX, sY;
		char cStep;
	} m_stWhetherObject[DEF_MAXWHETHEROBJECTS];

	struct {
		BOOL bIsQuestCompleted;
		short sWho, sQuestType, sContribution, sTargetType, sTargetCount, sX, sY, sRange;
		char cTargetName[22];
	} m_stQuest;

	struct {
		char cStatus;
		char cName[12];
	} m_stPartyMember[DEF_MAXPARTYMEMBERS];

	struct {
		short sX, sY;
		char cType;
		char cSide;
	} m_stCrusadeStructureInfo[DEF_MAXCRUSADESTRUCTURES];

	struct {
		char cName[12];
	} m_stPartyMemberNameList[DEF_MAXPARTYMEMBERS+1];
	
	// v2.171 2002-6-14
	struct {
		DWORD dwRefTime;
		int iGuildRank;
		char cCharName[12];
		char cGuildName[24];
	} m_stGuildName[DEF_MAXGUILDNAMES];

	struct {
		int iIndex;
		char mapname[12];
		int iX;
		int iY;
		int iCost;
	} m_stTeleportList[20];
	
	class YWSound m_DSound;
	class CSoundBuffer *	m_pCSound[DEF_MAXSOUNDEFFECTS];
	class CSoundBuffer *	m_pMSound[DEF_MAXSOUNDEFFECTS];
	class CSoundBuffer *	m_pESound[DEF_MAXSOUNDEFFECTS];
	class CSoundBuffer *    m_pBGM;
	class DXC_ddraw  m_DDraw;
	class DXC_dinput m_DInput;
	class CMisc      m_Misc;
	class CSprite  * m_pSprite[DEF_MAXSPRITES];
	class CSprite  * m_pTileSpr[DEF_MAXTILES];
	class CSprite  * m_pEffectSpr[DEF_MAXEFFECTSPR];
	class CMapData * m_pMapData;
	class XSocket * m_pGSock;
	class XSocket * m_pLSock;
	class CMsg    * m_pChatMsgList[DEF_MAXCHATMSGS];	// ĳ���� �Ӹ����� ä�� ����Ʈ 
	class CMsg    * m_pChatScrollList[DEF_MAXCHATSCROLLMSGS]; // ä�� ��ũ�ѿ� ����Ʈ 
	class CMsg    * m_pWhisperMsg[DEF_MAXWHISPERMSG];
	class CEffect * m_pEffectList[DEF_MAXEFFECTS];
	class CItem   * m_pItemList[DEF_MAXITEMS];
	class CItem   * m_pBankList[DEF_MAXBANKITEMS];
	class CMagic * m_pMagicCfgList[DEF_MAXMAGICTYPE];
	class CSkill * m_pSkillCfgList[DEF_MAXSKILLTYPE];
	class CMsg * m_pMsgTextList[DEF_TEXTDLGMAXLINES];
	class CMsg * m_pMsgTextList2[DEF_TEXTDLGMAXLINES];
	class CMsg * m_pAgreeMsgTextList[DEF_TEXTDLGMAXLINES];
	class CMsg * m_pExID;
	class CBuildItem * m_pBuildItemList[DEF_MAXBUILDITEMS];
	class CBuildItem * m_pDispBuildItemList[DEF_MAXBUILDITEMS];
	class CGameMonitor * m_pCGameMonitor;
	class CItem * m_pItemForSaleList[DEF_MAXMENUITEMS];    // �Ǹſ� ������ ����Ʈ 
	class CCharInfo * m_pCharList[4];
	class CMsg * m_pGameMsgList[DEF_MAXGAMEMSGS];
	class CItemName * m_pItemNameList[DEF_MAXITEMNAMES];
#if DEF_LANGUAGE > 2
	class CCurse m_curse;
#endif

	char* m_pInputBuffer;

	DWORD G_dwGlobalTime;
	DWORD m_dwCommandTime; //v2.15 ���� SpeedHack �� �ð�����..
	DWORD m_dwConnectMode; 
	DWORD m_dwTime;
	DWORD m_dwCurTime;
	DWORD m_dwCheckConnTime, m_dwCheckSprTime, m_dwCheckChatTime;
	DWORD m_dwDialogCloseTime;
	CInt  m_dwLogOutCountTime;//was DWORD
	DWORD m_dwRestartCountTime;
	DWORD m_dwWOFtime; //v1.4
	DWORD m_dwObserverCamTime;
	DWORD m_dwDamagedTime;
	DWORD m_dwSpecialAbilitySettingTime;
	DWORD m_dwCommanderCommandRequestedTime;
	DWORD m_dwTopMsgTime;
	DWORD m_dwEnvEffectTime;

	//v2.2
	DWORD m_dwMonsterEventTime;
	short m_sMonsterID;
	short m_sEventX, m_sEventY;


	//v2.183 Hunter Mode;
	BOOL m_bHunter;
	BOOL m_bAresden;
	BOOL m_bCitizen;
	//v2.183 Hunter Mode;

	BOOL m_bZoomMap;
	BOOL m_bIsProgramActive;
	CInt m_bCommandAvailable;//was BOOL
	BOOL m_bSoundFlag; // �ʱ�ȭ ���� ���� 
	BOOL m_bSoundStat, m_bMusicStat; // On/Off
	CInt m_bIsItemEquipped[DEF_MAXITEMS];//was BOOL
	CInt m_bIsItemDisabled[DEF_MAXITEMS];//was BOOL
	CInt m_bIsGetPointingMode;//was BOOL
	BOOL m_bEnterPressed, m_bEscPressed, m_bCtrlPressed, m_bRunningMode, m_bShiftPressed;
	CInt m_bIsDialogEnabled[41];//was BOOL
	BOOL m_bDialogTrans;
	BOOL m_bIsCombatMode;
	BOOL m_bIsSafeAttackMode;
	CInt m_bSkillUsingStatus;//was BOOL
	CInt m_bItemUsingStatus;//was BOOL
	BOOL m_bIsWhetherEffect;
	BOOL m_bSuperAttackMode;	// �ʻ�� ��� ��� 
	BOOL m_bIsObserverMode, m_bIsObserverCommanded;
	CInt m_bIsPoisoned;//was BOOL
	BOOL m_bIsFirstConn;							// ���� ���������� �˱� ���� 
	BOOL m_bIsConfusion;
	BOOL m_bIsRedrawPDBGS;
	BOOL m_bDrawFlagDir;
	BOOL m_bIsCrusadeMode;
	CInt m_bIsSpecialAbilityEnabled;//was BOOL
	BOOL m_bInputStatus;
	BOOL m_bToggleScreen;//2002.12.27 �Ȼ��� �߰�. ȭ���� �ٲٱ�.
	BOOL m_bIsSpecial;

	BOOL m_bIsF1HelpWindowEnabled;
	CInt m_bIsTeleportRequested;//was BOOL
	BOOL m_bIsPrevMoveBlocked;
	BOOL m_bIsHideLocalCursor;
	BOOL m_bIsCheckingGateway;
	CInt m_bForceDisconn;//was BOOL
	BOOL m_bForceAttack;
	BOOL m_bParalyze;

	short m_sFrameCount;
	short m_sFPS;
	DWORD m_dwFPStime;
	BOOL  m_bShowFPS;

	int m_iFightzoneNumber  ;			 // v1.4311-3 �߰� ���� ����  ����� ������ �ѹ�  
	int m_iFightzoneNumberTemp  ;      // ����Ǳ� ������ �ӽ÷� ������ ��ȣ�� �����Ѵ�.
	int m_iPlayerApprColor; // v1.4
	CInt m_iHP;//was int			// Hit Point
	CInt m_iMP;//was int			// Mana Point
	CInt m_iSP;//was int			// Staminar Point
	int m_iAC;						// Armour Class
	int m_iTHAC0;					// To Hit Armour Class 0

	int m_iLevel, m_iStr, m_iInt, m_iVit, m_iDex, m_iMag, m_iCharisma, m_iExp, m_iContribution;
	int m_iEnemyKillCount;
	int m_iPKCount;
	int m_iRewardGold;			// ����� ���� 
	int m_iGuildRank, m_iTotalGuildsMan;
	int m_iPointCommandType;
	// ���� ���� 
	int m_iTotalChar;
//	int m_iAccountStatus;
	short m_sMagicShortCut;
	int m_iLU_Point;
	int m_iCameraShakingDegree;
	int m_iSuperAttackLeft;	// v1.12 �ʻ�� ��� ī��Ʈ 
	int m_iAccntYear, m_iAccntMonth, m_iAccntDay;
	int m_iIpYear, m_iIpMonth, m_iIpDay;
	int m_iDownSkillIndex;

	int m_iIlusionOwnerH;
	int m_iApprColor_IE;
	int m_iInputX, m_iInputY;
	int m_iPDBGSdivX, m_iPDBGSdivY;			   // Pre-Draw Background Surface ���� ��ǥ 
	short m_sRecentShortCut;// �ֱٿ� ������ ����, ��, ���� (�������� ��� �ε���, ������ +100)
	short m_sShortCut[5];	//���� �߰��� 5���� ����Ű..v2.155
	int	m_iSpecialAbilityTimeLeftSec;
	int m_iDrawFlag;
	int m_iSpecialAbilityType;
	int m_iTimeLeftSecAccount, m_iTimeLeftSecIP;
	int m_iCrusadeDuty;
	int m_iLogServerPort;
//	int m_iRating; //Rating�� �޾Ƽ� ���� �ϵ� ����..�ϴ� �����..���߿� ���� Ǫ��..����

	int m_iPrevMoveX, m_iPrevMoveY;
	int m_iBlockYear, m_iBlockMonth, m_iBlockDay;
	unsigned char m_iTopMsgLastSec;
	int m_iConstructionPoint;
	int m_iWarContribution;
	int m_iConstructLocX, m_iConstructLocY;
	int m_iNetLagCount;
	int m_iTeleportLocX, m_iTeleportLocY;
	int m_iTotalPartyMember;
	int m_iPartyStatus;
	int m_iGizonItemUpgradeLeft;
	int m_iFeedBackCardIndex;

	short m_sItemEquipmentStatus[DEF_MAXITEMEQUIPPOS]; // ��ü ������ �������� ���� ����  
	short m_sPlayerX, m_sPlayerY;
	short m_sPlayerObjectID;
	short m_sPlayerType;
	short m_sPlayerAppr1, m_sPlayerAppr2, m_sPlayerAppr3, m_sPlayerAppr4;
	short m_sPlayerStatus;
	short m_sMCX, m_sMCY;
	short m_sCommX, m_sCommY;
	int   m_iCastingMagicType;
	short m_sDamageMove, m_sDamageMoveAmount;
	short m_sAppr1_IE, m_sAppr2_IE, m_sAppr3_IE, m_sAppr4_IE, m_sStatus_IE;
	short m_sViewDstX, m_sViewDstY;
	short m_sViewPointX, m_sViewPointY;
	short m_sVDL_X, m_sVDL_Y;

	WORD m_wCommObjectID;			// v1.4
	WORD m_wEnterGameType;
	WORD m_wR[16], m_wG[16], m_wB[16];
	WORD m_wWR[16], m_wWG[16], m_wWB[16];

	unsigned char m_cInputMaxLen;
	char m_cEdit[4];//�������� ����!!
	char G_cTxt[128];
	char m_cGameModeCount;
	char m_cBGMmapName[12];
	char m_cItemOrder[DEF_MAXITEMS];
	char m_cAmountString[12];
	char m_cLogOutCount;
	char m_cRestartCount;
	char m_cGameMode;
	char m_cWhisperIndex;  // v2.15 �Ӹ� ��ũ�ѿ� ����.
	char m_cAccountName[12];
	// 2002-09-16 #1 for Terra
#ifdef DEF_ACCOUNTLONG
	char m_cAccountLong[DEF_ACCOUNTLEN+1];
#endif
	char m_cAccountPassword[12];
	char m_cAccountAge[12];
	char m_cNewPassword[12];
	char m_cNewPassConfirm[12];
	char m_cAccountCountry[18];
	char m_cAccountSSN[32];
	char m_cEmailAddr[52];
	char m_cAccountQuiz[46];// v1.4334 Quiz ���� �߰� �������� �߰�
	char m_cAccountAnswer[22];
#if DEF_LANGUAGE == 2
	char m_cKeyCode[19];// v2.15 �����߰� �߱� KeyCode�� �������� �߰�
#endif
	char m_cPlayerName[12];
	char m_cPlayerDir;
	char m_cMsg[200];
	char m_cLocation[12];// �÷��̾� �Ҽ� ���� 
	char m_cCurLocation[12];// �÷��̾��� ���� ��ġ 
   	char m_cGuildName[22];
	char m_cMCName[12];
	char m_cMapName[12];
	char m_cMapMessage[32];
	char m_cMapIndex;
	char m_cPlayerTurn;
	char m_cCommand;
	char m_cCurFocus, m_cMaxFocus;
	char m_cEnterCheck, m_cTabCheck, m_cLeftArrowCheck;
	char m_cArrowPressed;
	char m_cLogServerAddr[16];
	char m_cChatMsg[64];
	char m_cBackupChatMsg[64];
	char m_cGender, m_cSkinCol, m_cHairStyle, m_cHairCol, m_cUnderCol;
	char m_ccStr, m_ccVit, m_ccDex, m_ccInt, m_ccMag, m_ccChr;
	char m_cLU_Str, m_cLU_Vit, m_cLU_Dex, m_cLU_Int, m_cLU_Mag, m_cLU_Char;
	char m_cDialogBoxOrder[42];
	char m_cMagicMastery[DEF_MAXMAGICTYPE];
	unsigned char m_cSkillMastery[DEF_MAXSKILLTYPE]; // v1.4
	char m_cWorldServerName[32];
	char m_cDetailLevel;
	char m_cMenuDir, m_cMenuDirCnt, m_cMenuFrame;
	char m_cSoundVolume, m_cMusicVolume;
	char m_cWhetherEffectType;
	char m_cWhetherStatus;
	char m_cIlusionOwnerType;
	char m_cName_IE[12];
	char m_sViewDX, m_sViewDY;
	char m_cCommandCount;
	char m_cLoading;
	char m_cDiscount; // ���� ������

	char m_cStatusMapName[12];
	char m_cTopMsg[64];
	char m_cTeleportMapName[12]; // ������ �ڷ���Ʈ �� �̸� 
	char m_cConstructMapName[12];
	char m_cGameServerName[22]; // v2.04 Gateway

	//2002. 10. 29 ������, ������ ������..
	char m_cItemDrop[25][25];

	RECT m_rcPlayerRect, m_rcBodyRect;
	HWND m_hWnd;
	
	HANDLE m_hPakFile;
	
	// ������, �ӼӸ��� ��ġ��..
	BOOL m_bWhisper;
	BOOL m_bShout;

	//2002. 10. 29 ������, ������ ������..
	BOOL m_bItemDrop; 
    int  m_iItemDropCnt;

#ifdef DEF_HTMLCOMMOM	//	�����̾�α�..	mando 
	void WebDialog();
#endif

};

#endif // !defined(AFX_GAME_H__0089D9E3_74E6_11D2_A8E6_00001C7030A6__INCLUDED_)
