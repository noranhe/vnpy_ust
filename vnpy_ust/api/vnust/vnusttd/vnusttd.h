//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnust.h"
#include "pybind11/pybind11.h"
#include "ust/HSSecuTradeApi.h"

using namespace pybind11;

//����
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPAUTHENTICATE 2
#define ONRSPUSERLOGIN 3
#define ONRSPQRYSTKACCT 4
#define ONRSPUSERPASSWORDUPDATE 5
#define ONRSPTRANSFER 6
#define ONRSPFUNDTRANS 7
#define ONRSPFUNDALLOC 8
#define ONRSPSTOCKTRANS 9
#define ONRSPORDERINSERT 10
#define ONRSPORDERACTION 11
#define ONRSPQRYHOLD 12
#define ONRSPQRYFUND 13
#define ONRSPQRYORDER 14
#define ONRSPQRYTRADE 15
#define ONRSPQRYEQUITY 16
#define ONRSPQRYSTKCODE 17
#define ONRTNORDER 18
#define ONRTNTRADE 19
#define ONRSPQRYETFCODE 20
#define ONRSPQRYETFCOMPONENT 21
#define ONRSPQRYIMPAWNDETAIL 22
#define ONRSPQRYBONDIMPAWNCONC 23
#define ONRSPCASHREPAY 24
#define ONRSPQRYENFINFUND 25
#define ONRSPQRYENSLOSTOCK 26
#define ONRSPQRYCREDITCOLLATERAL 27
#define ONRSPQRYCREDITUNDERLYING 28
#define ONRSPQRYCREDITRATE 29
#define ONRSPQRYCREDITASSET 30
#define ONRSPQRYCOMPACT 31
#define ONRSPCOMORDERINSERT 32
#define ONRSPCOMPACTAPPLY 33
#define ONRSPQRYAPPLYCODE 34
#define ONRSPQRYFUNDUF20 35
#define ONRSPQRYFUNDREALJOUR 36
#define ONRSPQRYCOMPACTREALJOUR 37
#define ONRSPQRYMAXENTRADENUM 38
#define ONRSPQRYSTOCKREALJOUR 39
#define ONRSPQRYBANKACCOUNT 40
#define ONRSPQRYHKSECURATE 41
#define ONRSPQRYASSUREAMOUNT 42
#define ONRSPQRYASSUREBACKAMOUNT 43
#define ONRSPQRYFUNDPEER 44


//API�ļ̳�ʵ��
///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class TdApi : public CHSSecuTradeSpi
{
private:
	CHSSecuTradeApi* api;            //API����
	thread task_thread;                    //�����߳�ָ�루��python���������ݣ�
	TaskQueue task_queue;                //�������
	bool active = false;                //����״̬

public:
	TdApi()
	{
	};

	~TdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------

	/// Description: ���ͻ����뽻�׺�̨��ʼ����ͨ�����ӣ����ӳɹ���˷������ص���
	virtual void OnFrontConnected();

	/// Description:���ͻ����뽻�׺�̨ͨ�������쳣ʱ���÷��������á�
	/// Others     :ͨ��GetApiErrorMsg(nResult)��ȡ��ϸ������Ϣ��
	virtual void OnFrontDisconnected(int nResult);

	/// Description:������֤
	virtual void OnRspAuthenticate(CHSSecuRspAuthenticateField *pRspAuthenticate, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�ͻ���¼
	virtual void OnRspUserLogin(CHSSecuRspUserLoginField *pRspUserLogin, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:֤ȯ�˻���Ϣ��ѯ
	virtual void OnRspQryStkAcct(CHSSecuRspQryStkAcctField *pRspRspQryStkAcct, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�������
	virtual void OnRspUserPasswordUpdate(CHSSecuRspUserPasswordUpdateField *pRspUserPasswordUpdate, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:����ת��
	virtual void OnRspTransfer(CHSSecuRspTransferField *pRspTransfer, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:���ٽ����뼯�н���֮���ʽ����
	virtual void OnRspFundTrans(CHSSecuRspFundTransField *pRspFundTrans, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:���ٽ��׶�����֮���ʽ����
	virtual void OnRspFundAlloc(CHSSecuRspFundAllocField *pRspFundAlloc, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:���ٽ����뼯�н���֮��ɷݵ���
	virtual void OnRspStockTrans(CHSSecuRspStockTransField *pRspStockTrans, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:����¼��
	virtual void OnRspOrderInsert(CHSSecuRspOrderInsertField *pRspOrderInsert, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:��������
	virtual void OnRspOrderAction(CHSSecuRspOrderActionField *pRspOrderAction, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�ֲֲ�ѯ
	virtual void OnRspQryHold(CHSSecuRspQryHoldField *pRspQryHold, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�ʽ��ѯ
	virtual void OnRspQryFund(CHSSecuRspQryFundField *pRspQryFund, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:������ѯ
	virtual void OnRspQryOrder(CHSSecuOrderField *pRspQryOrder, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�ɽ���ѯ
	virtual void OnRspQryTrade(CHSSecuTradeField *pRspQryTrade, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�¹��깺��Ȳ�ѯ
	virtual void OnRspQryEquity(CHSSecuRspQryEquityField *pRspQryEquity, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:֤ȯ�����ѯ
	virtual void OnRspQryStkcode(CHSSecuRspQryStkcodeField *pRspQryStkcode, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:����-�����ر�
	virtual void OnRtnOrder(CHSSecuOrderField *pRtnOrder);

	/// Description:����-�ɽ��ر�
	virtual void OnRtnTrade(CHSSecuTradeField *pRtnTrade);

	/// Description:ETF�����ѯ
	virtual void OnRspQryEtfcode(CHSSecuRspQryEtfcodeField *pRspQryEtfcode, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:ETF�ɷݹɲ�ѯ
	virtual void OnRspQryEtfcomponent(CHSSecuRspQryEtfcomponentField *pRspQryEtfcomponent, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:��Ѻ���ծȯ��ϸ��ѯ
	virtual void OnRspQryImpawnDetail(CHSSecuRspQryImpawnDetailField *pRspQryImpawnDetail, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:ծȯ��⼯�жȲ�ѯ
	virtual void OnRspQryBondImpawnConc(CHSSecuRspQryBondImpawnConcField *pRspQryBondImpawnConc, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�ֽ𻹿�
	virtual void OnRspCashRepay(CHSSecuRspCashRepayField *pRspCashRepay, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�����ʽ��ѯ
	virtual void OnRspQryEnfinFund(CHSSecuRspQryEnfinFundField *pRspQryEnfinFund, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:����֤ȯ��ѯ
	virtual void OnRspQryEnsloStock(CHSSecuRspQryEnsloStockField *pRspQryEnsloStock, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:����֤ȯ��ѯ
	virtual void OnRspQryCreditCollateral(CHSSecuRspQryCreditCollateralField *pRspQryCreditCollateral, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:���֤ȯ��ѯ
	virtual void OnRspQryCreditUnderlying(CHSSecuRspQryCreditUnderlyingField *pRspQryCreditUnderlying, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:������ȯ���ʲ�ѯ
	virtual void OnRspQryCreditRate(CHSSecuRspQryCreditRateField *pRspQryCreditRate, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�����ʲ���ѯ
	virtual void OnRspQryCreditAsset(CHSSecuRspQryCreditAssetField *pRspQryCreditAsset, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:���ں�Լ��ѯ
	virtual void OnRspQryCompact(CHSSecuRspQryCompactField *pRspQryCompact, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:��ϱ���¼��
	virtual void OnRspComOrderInsert(CHSSecuRspComOrderInsertField *pRspComOrderInsert, CHSSecuRspComInfoField *pRspComInfo, int nRequestID, bool bIsLast);

	/// Description:��Լչ������
	virtual void OnRspCompactApply(CHSSecuRspCompactApplyField *pRspCompactApply, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�¹��깺�����ѯ
	virtual void OnRspQryApplycode(CHSSecuRspQryApplycodeField *pRspQryApplycode, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:����̨�ʽ��ѯ
	virtual void OnRspQryFundUF20(CHSSecuRspQryFundUF20Field *pRspQryFundUF20, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�ʽ���ˮ��ѯ
	virtual void OnRspQryFundRealJour(CHSSecuRspQryFundRealJourField *pRspQryFundRealJour, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:ʵʱ��Լ��ˮ��ѯ
	virtual void OnRspQryCompactRealJour(CHSSecuRspQryCompactRealJourField *pRspQryCompactRealJour, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:������������ȡ
	virtual void OnRspQryMaxEntradeNum(CHSSecuRspQryMaxEntradeNumField *pRspQryMaxEntradeNum, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�ɷ���ˮ��ѯ
	virtual void OnRspQryStockRealJour(CHSSecuRspQryStockRealJourField *pRspQryStockRealJour, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�����˻���ѯ
	virtual void  OnRspQryBankAccount(CHSSecuRspQryBankAccountField *pRspQryBankAccount, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�۹�ͨ�ͻ����˽��׻��ʲ�ѯ
	virtual void OnRspQryHKSecurate(CHSSecuRspQryHKSecurateField *pRspQryHKSecurate, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�����ύ֤ȯ����������ѯ
	virtual void OnRspQryAssureAmount(CHSSecuRspQryAssureAmountField *pRspQryAssureAmount, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:����֤ȯ�ɷ���������ѯ 
	virtual void OnRspQryAssureBackAmount(CHSSecuRspQryAssureBackAmountField *pRspQryAssureBackAmount, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description:�Զ˿��ٽ��������ʽ��ѯ
	virtual void OnRspQryFundPeer(CHSSecuRspQryFundPeerField *pRspQryFundPeer, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processRspAuthenticate(Task *task);

	void processRspUserLogin(Task *task);

	void processRspQryStkAcct(Task *task);

	void processRspUserPasswordUpdate(Task *task);

	void processRspTransfer(Task *task);

	void processRspFundTrans(Task *task);

	void processRspFundAlloc(Task *task);

	void processRspStockTrans(Task *task);

	void processRspOrderInsert(Task *task);

	void processRspOrderAction(Task *task);

	void processRspQryHold(Task *task);

	void processRspQryFund(Task *task);

	void processRspQryOrder(Task *task);

	void processRspQryTrade(Task *task);

	void processRspQryEquity(Task *task);

	void processRspQryStkcode(Task *task);

	void processRtnOrder(Task *task);

	void processRtnTrade(Task *task);

	void processRspQryEtfcode(Task *task);

	void processRspQryEtfcomponent(Task *task);

	void processRspQryImpawnDetail(Task *task);

	void processRspQryBondImpawnConc(Task *task);

	void processRspCashRepay(Task *task);

	void processRspQryEnfinFund(Task *task);

	void processRspQryEnsloStock(Task *task);

	void processRspQryCreditCollateral(Task *task);

	void processRspQryCreditUnderlying(Task *task);

	void processRspQryCreditRate(Task *task);

	void processRspQryCreditAsset(Task *task);

	void processRspQryCompact(Task *task);

	void processRspComOrderInsert(Task *task);

	void processRspCompactApply(Task *task);

	void processRspQryApplycode(Task *task);

	void processRspQryFundUF20(Task *task);

	void processRspQryFundRealJour(Task *task);

	void processRspQryCompactRealJour(Task *task);

	void processRspQryMaxEntradeNum(Task *task);

	void processRspQryStockRealJour(Task *task);

	void processRspQryBankAccount(Task *task);

	void processRspQryHKSecurate(Task *task);

	void processRspQryAssureAmount(Task *task);

	void processRspQryAssureBackAmount(Task *task);

	void processRspQryFundPeer(Task *task);

	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int result) {};

	virtual void onRspAuthenticate(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspUserLogin(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryStkAcct(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspUserPasswordUpdate(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspTransfer(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspFundTrans(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspFundAlloc(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspStockTrans(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspOrderInsert(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspOrderAction(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryHold(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryFund(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryOrder(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryTrade(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryEquity(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryStkcode(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRtnOrder(const dict &data) {};

	virtual void onRtnTrade(const dict &data) {};

	virtual void onRspQryEtfcode(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryEtfcomponent(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryImpawnDetail(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryBondImpawnConc(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspCashRepay(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryEnfinFund(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryEnsloStock(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryCreditCollateral(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryCreditUnderlying(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryCreditRate(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryCreditAsset(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryCompact(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspComOrderInsert(const dict &data, const dict &info, int requestid, bool islast) {};

	virtual void onRspCompactApply(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryApplycode(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryFundUF20(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryFundRealJour(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryCompactRealJour(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryMaxEntradeNum(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryStockRealJour(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryBankAccount(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryHKSecurate(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryAssureAmount(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryAssureBackAmount(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryFundPeer(const dict &data, const dict &error, int requestid, bool islast) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void newSecuTradeApi(string pszFlowPath);

	void release();

	int init(string);

	int join();

	int exit();

	string getApiErrorMsg(int errorCode);

	int registerFront(string pszFrontAddress);

	int registerFensServer(string pszFensAddress, string pszAccountID);

	int registerSubModel(int eSubType);

	int reqAuthenticate(const dict &req, int reqid);

	int reqUserLogin(const dict &req, int reqid);

	int reqQryStkAcct(const dict &req, int reqid);

	int reqUserPasswordUpdate(const dict &req, int reqid);

	int reqTransfer(const dict &req, int reqid);

	int reqFundTrans(const dict &req, int reqid);

	int reqFundAlloc(const dict &req, int reqid);

	int reqStockTrans(const dict &req, int reqid);

	int reqOrderInsert(const dict &req, int reqid);

	int reqOrderAction(const dict &req, int reqid);

	int reqQryHold(const dict &req, int reqid);

	int reqQryFund(const dict &req, int reqid);

	int reqQryOrder(const dict &req, int reqid);

	int reqQryTrade(const dict &req, int reqid);

	int reqQryStkcode(const dict &req, int reqid);

	int reqQryEquity(const dict &req, int reqid);

	int reqQryEtfcode(const dict &req, int reqid);

	int reqQryEtfcomponent(const dict &req, int reqid);

	int reqQryImpawnDetail(const dict &req, int reqid);

	int reqQryBondImpawnConc(const dict &req, int reqid);

	int reqCashRepay(const dict &req, int reqid);

	int reqQryEnfinFund(const dict &req, int reqid);

	int reqQryEnsloStock(const dict &req, int reqid);

	int reqQryCreditCollateral(const dict &req, int reqid);

	int reqQryCreditUnderlying(const dict &req, int reqid);

	int reqQryCreditRate(const dict &req, int reqid);

	int reqQryCreditAsset(const dict &req, int reqid);

	int reqQryCompact(const dict &req, int reqid);

	int reqComOrderInsert(const dict &req, int reqid);

	int reqCompactApply(const dict &req, int reqid);

	int reqQryApplycode(const dict &req, int reqid);

	int reqQryFundUF20(const dict &req, int reqid);

	int reqQryFundRealJour(const dict &req, int reqid);

	int reqQryCompactRealJour(const dict &req, int reqid);

	int reqQryMaxEntradeNum(const dict &req, int reqid);

	int reqQryStockRealJour(const dict &req, int reqid);

	int reqQryBankAccount(const dict &req, int reqid);

	int reqQryHKSecurate(const dict &req, int reqid);

	int reqQryAssureAmount(const dict &req, int reqid);

	int reqQryAssureBackAmount(const dict &req, int reqid);

	int reqQryFundPeer(const dict &req, int reqid);

};