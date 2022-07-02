#ifndef _HS_SECU_TRADE_API_H_
#define _HS_SECU_TRADE_API_H_

#include "HSSecuStruct.h"

#if (defined WIN32) || (defined WIN64)  
#define TRADE_API_EXPORT _declspec(dllexport)
#else
#ifdef HSTRADEAPI_EXPORTS
#define TRADE_API_EXPORT __attribute__((visibility("default"))) 
#else
#define TRADE_API_EXPORT
#endif
#endif

/// �ص�����,�����ڻص����������϶��ʱ��ҵ��������Ӱ����Ϣ����
class CHSSecuTradeSpi
{
public:
	/// Description: ���ͻ����뽻�׺�̨��ʼ����ͨ�����ӣ����ӳɹ���˷������ص���
	virtual void OnFrontConnected(){};

	/// Description:���ͻ����뽻�׺�̨ͨ�������쳣ʱ���÷��������á�
	/// Others     :ͨ��GetApiErrorMsg(nResult)��ȡ��ϸ������Ϣ��
	virtual void OnFrontDisconnected(int nResult){};

	/// Description:������֤
	virtual void OnRspAuthenticate(CHSSecuRspAuthenticateField *pRspAuthenticate, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�ͻ���¼
	virtual void OnRspUserLogin(CHSSecuRspUserLoginField *pRspUserLogin, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:֤ȯ�˻���Ϣ��ѯ
	virtual void OnRspQryStkAcct(CHSSecuRspQryStkAcctField *pRspRspQryStkAcct, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�������
	virtual void OnRspUserPasswordUpdate(CHSSecuRspUserPasswordUpdateField *pRspUserPasswordUpdate, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:����ת��
	virtual void OnRspTransfer(CHSSecuRspTransferField *pRspTransfer, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:���ٽ����뼯�н���֮���ʽ����
	virtual void OnRspFundTrans(CHSSecuRspFundTransField *pRspFundTrans, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:���ٽ��׶�����֮���ʽ����
	virtual void OnRspFundAlloc(CHSSecuRspFundAllocField *pRspFundAlloc, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:���ٽ����뼯�н���֮��ɷݵ���
	virtual void OnRspStockTrans(CHSSecuRspStockTransField *pRspStockTrans, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:����¼��
	virtual void OnRspOrderInsert(CHSSecuRspOrderInsertField *pRspOrderInsert, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:��������
	virtual void OnRspOrderAction(CHSSecuRspOrderActionField *pRspOrderAction, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�ֲֲ�ѯ
	virtual void OnRspQryHold(CHSSecuRspQryHoldField *pRspQryHold, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�ʽ��ѯ
	virtual void OnRspQryFund(CHSSecuRspQryFundField *pRspQryFund, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:������ѯ
	virtual void OnRspQryOrder(CHSSecuOrderField *pRspQryOrder, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�ɽ���ѯ
	virtual void OnRspQryTrade(CHSSecuTradeField *pRspQryTrade, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�¹��깺��Ȳ�ѯ
	virtual void OnRspQryEquity(CHSSecuRspQryEquityField *pRspQryEquity, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:֤ȯ�����ѯ
	virtual void OnRspQryStkcode(CHSSecuRspQryStkcodeField *pRspQryStkcode, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};	

	/// Description:����-�����ر�
	virtual void OnRtnOrder(CHSSecuOrderField *pRtnOrder) {};

	/// Description:����-�ɽ��ر�
	virtual void OnRtnTrade(CHSSecuTradeField *pRtnTrade) {};

	/// Description:ETF�����ѯ
	virtual void OnRspQryEtfcode(CHSSecuRspQryEtfcodeField *pRspQryEtfcode, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:ETF�ɷݹɲ�ѯ
	virtual void OnRspQryEtfcomponent(CHSSecuRspQryEtfcomponentField *pRspQryEtfcomponent, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:��Ѻ���ծȯ��ϸ��ѯ
	virtual void OnRspQryImpawnDetail(CHSSecuRspQryImpawnDetailField *pRspQryImpawnDetail, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:ծȯ��⼯�жȲ�ѯ
	virtual void OnRspQryBondImpawnConc(CHSSecuRspQryBondImpawnConcField *pRspQryBondImpawnConc, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�ֽ𻹿�
	virtual void OnRspCashRepay(CHSSecuRspCashRepayField *pRspCashRepay, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�����ʽ��ѯ
	virtual void OnRspQryEnfinFund(CHSSecuRspQryEnfinFundField *pRspQryEnfinFund, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	/// Description:����֤ȯ��ѯ
	virtual void OnRspQryEnsloStock(CHSSecuRspQryEnsloStockField *pRspQryEnsloStock, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	/// Description:����֤ȯ��ѯ
	virtual void OnRspQryCreditCollateral(CHSSecuRspQryCreditCollateralField *pRspQryCreditCollateral, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	/// Description:���֤ȯ��ѯ
	virtual void OnRspQryCreditUnderlying(CHSSecuRspQryCreditUnderlyingField *pRspQryCreditUnderlying, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	/// Description:������ȯ���ʲ�ѯ
	virtual void OnRspQryCreditRate(CHSSecuRspQryCreditRateField *pRspQryCreditRate, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	/// Description:�����ʲ���ѯ
	virtual void OnRspQryCreditAsset(CHSSecuRspQryCreditAssetField *pRspQryCreditAsset, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	/// Description:���ں�Լ��ѯ
	virtual void OnRspQryCompact(CHSSecuRspQryCompactField *pRspQryCompact, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};
	
	/// Description:��ϱ���¼��
	virtual void OnRspComOrderInsert(CHSSecuRspComOrderInsertField *pRspComOrderInsert, CHSSecuRspComInfoField *pRspComInfo, int nRequestID, bool bIsLast) {};

	/// Description:��Լչ������
	virtual void OnRspCompactApply(CHSSecuRspCompactApplyField *pRspCompactApply, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�¹��깺�����ѯ
	virtual void OnRspQryApplycode(CHSSecuRspQryApplycodeField *pRspQryApplycode, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	/// Description:����̨�ʽ��ѯ
	virtual void OnRspQryFundUF20(CHSSecuRspQryFundUF20Field *pRspQryFundUF20, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	/// Description:�ʽ���ˮ��ѯ
	virtual void OnRspQryFundRealJour(CHSSecuRspQryFundRealJourField *pRspQryFundRealJour, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	/// Description:ʵʱ��Լ��ˮ��ѯ
	virtual void OnRspQryCompactRealJour(CHSSecuRspQryCompactRealJourField *pRspQryCompactRealJour, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	/// Description:������������ȡ
	virtual void OnRspQryMaxEntradeNum(CHSSecuRspQryMaxEntradeNumField *pRspQryMaxEntradeNum, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�ɷ���ˮ��ѯ
	virtual void OnRspQryStockRealJour(CHSSecuRspQryStockRealJourField *pRspQryStockRealJour, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�����˻���ѯ
	virtual void OnRspQryBankAccount(CHSSecuRspQryBankAccountField *pRspQryBankAccount, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	/// Description:�۹�ͨ�ͻ����˽��׻��ʲ�ѯ
	virtual void OnRspQryHKSecurate(CHSSecuRspQryHKSecurateField *pRspQryHKSecurate, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:�����ύ֤ȯ����������ѯ
	virtual void OnRspQryAssureAmount(CHSSecuRspQryAssureAmountField *pRspQryAssureAmount, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	/// Description:����֤ȯ�ɷ���������ѯ 
	virtual void OnRspQryAssureBackAmount(CHSSecuRspQryAssureBackAmountField *pRspQryAssureBackAmount, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
	/// Description:�Զ˿��ٽ��������ʽ��ѯ
	virtual void OnRspQryFundPeer(CHSSecuRspQryFundPeerField *pRspQryFundPeer, CHSSecuRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

///����
class  CHSSecuTradeApi
{
public:
	/// Description: ɾ���ӿڶ�����
	virtual void ReleaseApi() = 0;

	/// Description: ��ʼ������
	///              pszLicFile            ͨѶ֤��
	///              pszSafeLevel          ��ȫ����
	///              pszPwd                ͨѶ����
	///              pszSslFile            SSL֤��
	///              pszSslPwd             SSL����
	virtual int Init(const char *pszLicFile, const char *pszSafeLevel = "", const char *pszPwd = "", const char *pszSslFile = "", const char *pszSslPwd = "") = 0;

	/// Description: API�ͽ��׹�̨�������ӣ����ӽ����ɹ������̻߳�ȴ��û��������߳��˳�
	/// Return     : int 0��ʾ���ӽ����ɹ��������ʾʧ�ܣ�ͨ������GetApiErrorInfo���Ի�ȡ��ϸ������Ϣ
	virtual int Join() = 0;

	/// Description: ע��ص��ӿ�
	/// Input      : pSpi            �����Իص��ӿ����ʵ��     
	virtual void RegisterSpi(CHSSecuTradeSpi *pSpi) = 0;

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	virtual int RegisterFront(const char *pszFrontAddress) = 0;

	///ע��Fens�����ַ
	/// Input      : pszFensAddress            Fens�����ַ
	/// Input      : pszAccountID              �˺�
	virtual int RegisterFensServer(const char *pszFensAddress, const char *pszAccountID) = 0;

	/// Description: ע�ᶩ��ģʽ
	/// Input      : ���ķ�ʽ
	///                 HS_TERT_RESTART://�ӱ������տ�ʼ�ش�
	///                 HS_TERT_RESUME: //���ϴ��յ�������
	///                 HS_TERT_QUICK:  //�ӵ�¼�����µĿ�ʼ��
	virtual int RegisterSubModel(SUB_TERT_TYPE eSubType) = 0;
	
	/// Description: ��ô�����ϸ��Ϣ
	virtual const char* GetApiErrorMsg(int nErrorCode) = 0;

	/// Description:������֤ 
	virtual int  ReqAuthenticate(CHSSecuReqAuthenticateField *pReqAuthenticate, int nRequestID) = 0;

	/// Description:�ͻ���¼
	virtual int  ReqUserLogin(CHSSecuReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	/// Description:֤ȯ�˻���Ϣ��ѯ
	virtual int  ReqQryStkAcct(CHSSecuReqQryStkAcctField *pReqQryStkAcct, int nRequestID) = 0;

	/// Description:�������
	virtual int  ReqUserPasswordUpdate(CHSSecuReqUserPasswordUpdateField *pReqUserPasswordUpdate, int nRequestID) = 0;

	/// Description:��֤ת��
	virtual int  ReqTransfer(CHSSecuReqTransferField *pReqTransfer, int nRequestID) = 0;

	/// Description:���ٽ����뼯�н���֮���ʽ����
	virtual int  ReqFundTrans(CHSSecuReqFundTransField *pReqFundTrans, int nRequestID) = 0;

	/// Description:���ٽ��׶�����֮���ʽ����
	virtual int  ReqFundAlloc(CHSSecuReqFundAllocField *pReqFundAlloc, int nRequestID) = 0;

	/// Description:���ٽ����뼯�н���֮��ɷݵ���
	virtual int  ReqStockTrans(CHSSecuReqStockTransField *pReqStockTrans, int nRequestID) = 0;

	/// Description:����¼��
	virtual int  ReqOrderInsert(CHSSecuReqOrderInsertField *pReqOrderInsert, int nRequestID) = 0;

	/// Description:��������
	virtual int  ReqOrderAction(CHSSecuReqOrderActionField *pReqOrderAction, int nRequestID) = 0;

	/// Description:�ֲֲ�ѯ
	virtual int  ReqQryHold(CHSSecuReqQryHoldField *pReqQryHold, int nRequestID) = 0;

	/// Description:�ʽ��ѯ
	virtual int  ReqQryFund(CHSSecuReqQryFundField *pReqQryFund, int nRequestID) = 0;

	/// Description:������ѯ
	virtual int  ReqQryOrder(CHSSecuReqQryOrderField *pReqQryOrder, int nRequestID) = 0;

	/// Description:�ɽ���ѯ
	virtual int  ReqQryTrade(CHSSecuReqQryTradeField *pReqQryTrade, int nRequestID) = 0;

	/// Description:֤ȯ�����ѯ
	virtual int  ReqQryStkcode(CHSSecuReqQryStkcodeField *pReqQryStkcode, int nRequestID) = 0;
	
	/// Description:�¹��깺��Ȳ�ѯ
	virtual int  ReqQryEquity(CHSSecuReqQryEquityField *pReqQryEquity, int nRequestID) = 0;

	/// Description:ETF�����ѯ
	virtual int  ReqQryEtfcode(CHSSecuReqQryEtfcodeField *pReqQryEtfcode, int nRequestID) = 0;

	/// Description:ETF�ɷݹɲ�ѯ
	virtual int  ReqQryEtfcomponent(CHSSecuReqQryEtfcomponentField *pReqQryEtfcomponent, int nRequestID) = 0;

	/// Description:��Ѻ���ծȯ��ϸ��ѯ
	virtual int  ReqQryImpawnDetail(CHSSecuReqQryImpawnDetailField *pReqQryImpawnDetail, int nRequestID) = 0;

	/// Description:ծȯ��⼯�жȲ�ѯ
	virtual int  ReqQryBondImpawnConc(CHSSecuReqQryBondImpawnConcField *pReqQryBondImpawnConc, int nRequestID) = 0;

	/// Description:�ֽ𻹿�
	virtual int  ReqCashRepay(CHSSecuReqCashRepayField *pReqCashRepay, int nRequestID) = 0;

	/// Description:�����ʽ��ѯ
	virtual int  ReqQryEnfinFund(CHSSecuReqQryEnfinFundField *pReqQryEnfinFund, int nRequestID) = 0;

	/// Description:����֤ȯ��ѯ
	virtual int  ReqQryEnsloStock(CHSSecuReqQryEnsloStockField *pReqQryEnsloStock, int nRequestID) = 0;

	/// Description:����֤ȯ��ѯ
	virtual int  ReqQryCreditCollateral(CHSSecuReqQryCreditCollateralField *pReqQryCreditCollateral, int nRequestID) = 0;

	/// Description:���֤ȯ��ѯ
	virtual int  ReqQryCreditUnderlying(CHSSecuReqQryCreditUnderlyingField *pReqQryCreditUnderlying, int nRequestID) = 0;

	/// Description:������ȯ���ʲ�ѯ
	virtual int  ReqQryCreditRate(CHSSecuReqQryCreditRateField *pReqQryCreditRate, int nRequestID) = 0;

	/// Description:�����ʲ���Ϣ��ѯ
	virtual int  ReqQryCreditAsset(CHSSecuReqQryCreditAssetField *pReqQryCreditAsset, int nRequestID) = 0;

	/// Description:���ں�Լ��ѯ
	virtual int  ReqQryCompact(CHSSecuReqQryCompactField *pReqQryCompact, int nRequestID) = 0;

	/// Description:��ϱ���¼��
	virtual int  ReqComOrderInsert(CHSSecuReqComOrderInsertField *pReqComOrderInsert, int nRequestID) = 0;

	/// Description:��Լչ������
	virtual int  ReqCompactApply(CHSSecuReqCompactApplyField *pReqCompactApply, int nRequestID) = 0;

	/// Description:�¹��깺�����ѯ
	virtual int  ReqQryApplycode(CHSSecuReqQryApplycodeField *pReqQryApplycode, int nRequestID) = 0;

	///Description:����̨�ʽ��ѯ
	virtual int  ReqQryFundUF20(CHSSecuReqQryFundUF20Field *pReqQryFundUF20, int nRequestID) = 0;

	///Description:�ʽ���ˮ��ѯ
	virtual int  ReqQryFundRealJour(CHSSecuReqQryFundRealJourField *pReqQryFundRealJour, int nRequestID) = 0;

	///Description:��Լ��ˮ���ѯ
	virtual int  ReqQryCompactRealJour(CHSSecuReqQryCompactRealJourField *pReqQryCompactRealJour, int nRequestID) = 0;

	///Description:������������ȡ
	virtual int  ReqQryMaxEntradeNum(CHSSecuReqQryMaxEntradeNumField *pReqQryMaxEntradeNum, int nRequestID) = 0;

	///Description:�ɷ���ˮ��ѯ
	virtual int  ReqQryStockRealJour(CHSSecuReqQryStockRealJourField *pReqQryStockRealJour, int nRequestID) = 0;

	///Description:�����˺Ų�ѯ
	virtual int  ReqQryBankAccount(CHSSecuReqQryBankAccountField *pReqQueryBankAccount, int nRequestID) = 0;

	/// Description:�۹�ͨ�ͻ����˽��׻��ʲ�ѯ
	virtual int  ReqQryHKSecurate(CHSSecuReqQryHKSecurateField *pReqQryHKSecurate, int nRequestID) = 0;

	///Description:�����ύ֤ȯ����������ѯ
	virtual int  ReqQryAssureAmount(CHSSecuReqQryAssureAmountField *pReqQryAssureAmount, int nRequestID) = 0;

	///Description:����֤ȯ�ɷ���������ѯ
	virtual int  ReqQryAssureBackAmount(CHSSecuReqQryAssureBackAmountField *pReqQryAssureBackAmount, int nRequestID) = 0;

	/// Description:�Զ˿��ٽ��������ʽ��ѯ
	virtual int  ReqQryFundPeer(CHSSecuReqQryFundPeerField *pReqQryFundPeer, int nRequestID) = 0;

	protected:
	~CHSSecuTradeApi(){};
};

extern   "C"
{
	/// Description: ��ȡAPI�汾��
	TRADE_API_EXPORT const char*  GetSecuTradeApiVersion();

	/// Description: �������׽ӿ�    
	/// Input      : pszFlowPath    ����·����Ҫ��Ϊgbk���� 
	TRADE_API_EXPORT CHSSecuTradeApi* NewSecuTradeApi(const char *pszFlowPath);
}

#endif