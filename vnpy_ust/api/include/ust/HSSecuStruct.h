#ifndef _HS_SECU_API_STRUCT_H_
#define _HS_SECU_API_STRUCT_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HSDataType.h"


//#pragma pack(push,8)
///Ӧ����Ϣ
struct CHSSecuRspInfoField
{
    /// �������
	HSErrorID                    ErrorID;
    /// ������ʾ
    HSErrorMsg					 ErrorMsg;
};

///������֤
struct CHSSecuReqAuthenticateField
{
	/// �ʲ��˺�
	HSAccountID                   AccountID;
	/// �ͻ���id
	HSAppID                       AppID;
	/// ��֤��
	HSAuthCode                    AuthCode;
};

///������֤Ӧ��
struct CHSSecuRspAuthenticateField
{
	/// �ʲ��˺�
	HSAccountID                   AccountID;
	/// �ͻ���id
	HSAppID                       AppID;
	/// ��֤��
	HSAuthCode                    AuthCode;
};

///�ͻ���¼
struct CHSSecuReqUserLoginField
{
	/// �ʲ��˺�
	HSAccountID                   AccountID;
	/// ��������
	HSPassword                    Password;	
    /// Ͷ���߶�Ӧ�����
    HSUserApplicationType         UserApplicationType;
    /// Ͷ���߶�Ӧ����Ϣ
    HSUserApplicationInfo         UserApplicationInfo;
    /// Ͷ����Mac��ַ
    HSMacAddress                  MacAddress;
    /// Ͷ����IP��ַ
    HSIPAddress                   IPAddress;
	/// �û�վ����Ϣ
	HSUserStationInfo             UserStationInfo;
};

///�ͻ���¼Ӧ��
struct CHSSecuRspUserLoginField
{
    /// Ӫҵ����
	HSNum                    	  BranchID;
    /// �ʲ��˺�
	HSAccountID                   AccountID;
	/// �ʲ�����
	HSAssetProp					  AssetProp;
    /// �ͻ�����
    HSUserName					  UserName;
	/// ������
	HSDate						  TradingDay;
	/// �������ã����ػỰ�ϴ����ί�����ã�
	HSRef						  OrderRef;
	/// ��ǰ�Ự���
	HSSessionID					  SessionID;
	/// �ͻ����
	HSUserID					  UserID;
};

///֤ȯ�˻���Ϣ��ѯ
struct CHSSecuReqQryStkAcctField
{
	///����������
	HSExchangeID ExchangeID;
};

///֤ȯ�˻���Ϣ��ѯӦ��
struct CHSSecuRspQryStkAcctField
{
	///�ʲ��˻�
	HSAccountID AccountID;
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ�˺�
	HSStockAccount StockAccount;
};

///�������
struct CHSSecuReqUserPasswordUpdateField
{
    /// ��������
	HSPasswordType				  PasswordType;
    /// ����
	HSPassword                    Password;
    /// ������
	HSPassword                    NewPassword;
};

///�������Ӧ��
struct CHSSecuRspUserPasswordUpdateField
{
};

///����ת��
struct CHSSecuReqTransferField
{
	/// ���д���
	HSBankID                      BankID;
	/// ת������
	HSTransferType                TransferType;
	/// �������
	HSBalance                     OccurBalance;
	/// �ʽ�����
	HSPassword                    FundPassword;
	/// ��������
	HSPassword                    BankPassword;
	/// ����
	HSCurrencyID                  CurrencyID;
	/// ת�˳���
	HSOccasion				      TransferOccasion;
};

///����ת��Ӧ��
struct CHSSecuRspTransferField
{
	/// ת����ˮ
	HSNum                         TransferSerialID;
	/// ���д���
	HSBankID                      BankID;
	/// ת������
	HSTransferType                TransferType;
	/// �������
	HSBalance                     OccurBalance;
	/// ����
	HSCurrencyID                  CurrencyID;
	/// ת�˳���
	HSOccasion				      TransferOccasion;
};

///���ٽ����뼯�н���֮���ʽ����
struct CHSSecuReqFundTransField
{
	/// ��������
	HSTransDirection              TransDirection;
	/// ����
	HSCurrencyID				  CurrencyID;
	/// �������
	HSBalance                     OccurBalance;
};

///���ٽ����뼯�н���֮���ʽ����Ӧ��
struct CHSSecuRspFundTransField
{
	/// �ʽ������ˮ
	HSNum						  FundTransSerialID;
};

///���ٽ��׶�����֮���ʽ����
struct CHSSecuReqFundAllocField
{
	/// ��������
	HSTransDirection              TransDirection;
	/// ����
	HSCurrencyID				  CurrencyID;
	/// �������
	HSBalance                     OccurBalance;
	/// �Զ˿��ٽ��׽ڵ�ţ�˫����ģʽ�£�����0��API�����л�ȡ��ȷ�ڵ�ţ�����������ģʽ�£�������ұ������0��
	HSSysnodeID					  SysnodeID;
};

///���ٽ��׶�����֮���ʽ����Ӧ��
struct CHSSecuRspFundAllocField
{
	/// �ʽ������ˮ
	HSNum						  FundTransSerialID;
};

///���ٽ����뼯�н���֮��ɷݵ�������
struct CHSSecuReqStockTransField
{
	/// ��������
	HSTransDirection             TransDirection;
	/// ֤ȯ�˺�
	HSStockAccount				 StockAccount;
	/// ����������
	HSExchangeID				 ExchangeID;
	/// ֤ȯ����
	HSStockCode                  StockCode;
	/// ��������
	HSVolume                     OccurVolume;
};

///���ٽ����뼯�н���֮��ɷݵ���Ӧ��
struct CHSSecuRspStockTransField
{
	/// �ɷݵ�����ˮ
	HSNum						  StockTransSerialID;
};

///����¼������
struct CHSSecuReqOrderInsertField
{
    /// ����������
	HSExchangeID                  ExchangeID;
    /// ֤ȯ����
	HSStockCode                   StockCode;
    /// ����ָ��
	HSOrderCommand				  OrderCommand;
    /// ��������
    HSOrderDirection              Direction;
    /// �����۸�
    HSPrice                       OrderPrice;
    /// ��������
	HSVolume                      OrderVolume;
    /// ֤ȯ�˺�
    HSStockAccount                StockAccount;
    /// ��������
	HSRef                         OrderRef;
    /// ͷ������
	HSCashGroupProp               CashGroupProp;
    /// ��Լ���
	HSCompactID                   CompactID;
	/// �������κ�
	HSBatchNo                     BatchNo;
	/// ͨ������
	HSChannelType                 ChannelType;  
	/// �ɷ�����
  	HSStockProperty            	  StockProperty;
	/// �ͻ��˱������
	HSClientOrderID			      ClientOrderID;
	/// �ֻ��˻���������
	HSPassword					  SecuPassword;	
};
///����¼��Ӧ��
struct CHSSecuRspOrderInsertField
{
	///��������
	HSOrderPartition OrderPartition;
	///���͹�˾��������
	HSBrokerOrderID	BrokerOrderID;
	///�Ự���
	HSSessionID SessionID;
	///��������
	HSRef OrderRef;
	///�������κ�
	HSBatchNo BatchNo;
	///�ͻ��˱������
	HSClientOrderID ClientOrderID;
};

///������������
struct CHSSecuReqOrderActionField
{
	///���������ı�������
	HSOrderPartition OrderPartition;
	///���������ľ��͹�˾��������
	HSBrokerOrderID	BrokerOrderID;
	///���������ĻỰ���
	HSSessionID SessionID;
	///���������ı�������
	HSRef OrderRef;
	///���������Ŀͻ��˱������
	HSClientOrderID ClientOrderID;
};

///��������Ӧ��
struct CHSSecuRspOrderActionField
{
	///�����ı�������
	HSOrderPartition OrderPartition;
	///�����ľ��͹�˾��������
	HSBrokerOrderID	BrokerOrderID;
	///���������ı�������
	HSOrderPartition OrigOrderPartition;
	///���������ľ��͹�˾��������
	HSBrokerOrderID	OrigBrokerOrderID;
	///���������ĻỰ���
	HSSessionID OrigSessionID;
	///���������ı�������
	HSRef OrigOrderRef;
	///���������Ŀͻ��˱������
	HSClientOrderID OrigClientOrderID;
};

///������ѯ
struct CHSSecuReqQryOrderField
{
	///��������
	HSOrderPartition OrderPartition;
	///���͹�˾��������
    HSBrokerOrderID BrokerOrderID;
	///�Ự���
	HSSessionID SessionID;
	///��������
	HSRef OrderRef;
	///�ͻ��˱������
	HSClientOrderID ClientOrderID;
};
///������ѯӦ������
struct CHSSecuOrderField
{
	///��������
	HSDate TradingDay;
	///�ʲ��˻�
	HSAccountID AccountID;
	///��������
	HSOrderPartition OrderPartition;
	///���͹�˾��������
	HSBrokerOrderID BrokerOrderID;
	///�Ự���
	HSSessionID SessionID;
	///��������
	HSRef OrderRef;
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ�˺�
	HSStockAccount StockAccount;
	///֤ȯ����
	HSStockCode StockCode;
	///��������
	HSOrderDirection Direction;
	///�����۸�
	HSPrice OrderPrice;
	///��������
	HSVolume OrderVolume;
	///����״̬
	HSOrderStatus OrderStatus;
    /// ����ָ��
	HSOrderCommand OrderCommand;
	///�걨ʱ��
	HSTime ReportTime;
	///�ϵ�ԭ��
	HSErrorMsg ErrorMsg;
	///�ɽ�����
	HSVolume TradeVolume;
	///�������κ�
	HSBatchNo BatchNo;
	///��������
	HSVolume WithdrawVolume;
	///����ʱ��
	HSTime OrderTime;  
	 ///���͹�˾��������
  	 HSBrokerOrderID BrokerWithdrawOrderID;
	///ί�ж�����
	HSBalance FrozenBalance;
	///ί�ж������
	HSBalance FrozenFare;
    /// Ӫҵ����
	HSNum BranchID;
	/// ��������״̬
	HSOrderAssStatus OrderAssStatus;
	/// ��������״̬
	HSOrderStatus WithdrawOrderStatus;
	///����ʱ��
	HSTime OccurTime;
	///�ͻ��˱������
	HSClientOrderID ClientOrderID;
	///֤ȯ����
	HSStockName	StockName;
	///�ɽ��۸�
	HSPrice TradePrice;
	///�ɽ����
	HSBalance BusinessBalance;

};
///�ʽ��ѯ
struct CHSSecuReqQryFundField
{
	///�������
	HSCurrencyID CurrencyID;
};

///�ʽ��ѯӦ��
struct CHSSecuRspQryFundField
{
	///�������
	HSCurrencyID CurrencyID;
	///��ǰ���
	HSBalance CurrentBalance;
	///�ڳ����
	HSBalance BeginBalance;
	///�����ʽ�
	HSBalance AvailableBalance;
	///��ȡ���
	HSBalance FetchBalance;
	///֤ȯ��ֵ
	HSBalance MarketValue;
	/// ���ʲ�
	HSBalance TotalAsset;
};

///����̨�ʽ��ѯ
struct CHSSecuReqQryFundUF20Field
{
	///�������
	HSCurrencyID CurrencyID;
};

///����̨�ʽ��ѯӦ��
struct CHSSecuRspQryFundUF20Field
{
	///�������
	HSCurrencyID CurrencyID;
	///��ǰ���
	HSBalance CurrentBalance;
	///�����ʽ�
	HSBalance AvailableBalance;
	///��ȡ���
	HSBalance FetchBalance;
	///������
	HSBalance FrozenBalance;
	///�ⶳ���
	HSBalance UnfrozenBalance;
	/// ���ʲ�
	HSBalance TotalAsset;
};

///�ֲֲ�ѯ
struct CHSSecuReqQryHoldField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
};

///�ֲֲ�ѯӦ��
struct CHSSecuRspQryHoldField
{
	///�ʲ��˻�
	HSAccountID AccountID;
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ�˺�
	HSStockAccount StockAccount;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ����
	HSStockName	StockName;
	///֤ȯ���
	HSStockType	StockType;
	///��ǰ����
	HSVolume CurrentVolume;
	///��������
	HSVolume AvailableVolume;
	///�������
	HSPrice	AvBuyPrice;
	///��ֵ��
	HSPrice AssetPrice;	
	///ʵ��ӯ��
	HSBalance AchvProfit;
	///�ڳ�����
	HSVolume BeginVolume;
	///�ر���������
	HSVolume RealBuyVolume;
	///�ر���������
	HSVolume RealSellVolume;
	///δ����������
	HSVolume UncomeBuyVolume;
	///δ����������
	HSVolume UncomeSellVolume;
	///����ӯ��
	HSBalance FloatProfit;
	///��ֵ��
	HSPrice MarketValue;
};

///�¹��깺��Ȳ�ѯ����
struct CHSSecuReqQryEquityField
{
	///����������
	HSExchangeID ExchangeID;
};

///�¹��깺��Ȳ�ѯӦ��
struct CHSSecuRspQryEquityField
{
	///��������
	HSDate TradingDay;
	///��֧����
	HSNum BranchID;
	///�ʲ��˻�
	HSAccountID AccountID;
	///֤ȯ�˺�
	HSStockAccount StockAccount;
	///����������
	HSExchangeID ExchangeID;
	///��������
	HSVolume AvailableVolume;
	///�ƴ����������
	HSVolume StarAvailableVolume;
};

///�ɽ���ѯ��������
struct CHSSecuReqQryTradeField
{
	///��������
	HSOrderPartition OrderPartition;
	///���͹�˾��������
	HSBrokerOrderID BrokerOrderID;
	///�Ự���
	HSSessionID SessionID;
	///��������
	HSRef OrderRef;
	///�ͻ��˱������
	HSClientOrderID ClientOrderID;
};
///�ɽ���ѯӦ������
struct CHSSecuTradeField
{
	///��������
	HSDate TradingDay;
	///�ʲ��˻�
	HSAccountID AccountID;
	///��������
	HSOrderPartition OrderPartition;
	///���͹�˾��������
	HSBrokerOrderID BrokerOrderID;
	///�Ự���
	HSSessionID SessionID;
	///��������
	HSRef OrderRef;
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ�˺�
	HSStockAccount StockAccount;
	///֤ȯ����
	HSStockCode StockCode;
	///��������
	HSOrderDirection Direction;
	///����ָ��
	HSOrderCommand OrderCommand;
	///�ɽ�״̬
	HSTradeStatus TradeStatus;
	///�ɽ����
	HSTradeID TradeID;
	///�ɽ�����
	HSVolume TradeVolume;
	///�ɽ��۸�
	HSPrice TradePrice;
	///�ɽ�ʱ��
	HSTime TradeTime;
	///�ϵ�ԭ��
	HSErrorMsg ErrorMsg;
	///�������κ�
	HSBatchNo BatchNo;
	///���͹�˾��������
  	HSBrokerOrderID BrokerWithdrawOrderID;  
	///�ɽ����
	HSBalance BusinessBalance;
    /// Ӫҵ����
	HSNum BranchID;
	///����״̬
	HSOrderStatus OrderStatus;
	///����ʱ��
	HSTime OccurTime;
	///�ͻ��˱������
	HSClientOrderID ClientOrderID;
};

///�����ʽ��ѯ����
struct CHSSecuReqQryEnfinFundField
{
	///ͷ������
	HSCashGroupProp CashGroupProp;
};

///�����ʽ��ѯӦ��
struct CHSSecuRspQryEnfinFundField
{
	///�����ʽ�
	HSBalance AvailableBalance;
};

///����֤ȯ��ѯ����
struct CHSSecuReqQryEnsloStockField
{
	///�г����
	HSExchangeID ExchangeID;
	///֤ȯ���
	HSStockType StockType;
	///֤ȯ����
	HSStockCode StockCode;
	///ͷ������
	HSCashGroupProp CashGroupProp;
};

///����֤ȯ��ѯӦ��
struct CHSSecuRspQryEnsloStockField
{
	///�г����
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ���
	HSStockType StockType;
	///֤ȯ����
	HSStockName StockName;
	///��ȯ��֤�����
	HSRate ShortSellRatio;
	///��ȯ״̬
	HSStatus ShortSellStatus;
	///��������
	HSVolume AvailableVolume;
	///ͷ������
	HSCashGroupProp CashGroupProp;
};

///֤ȯ�����ѯ����
struct CHSSecuReqQryStkcodeField
{
	///����������
	HSExchangeID ExchangeID;	
	///֤ȯ����
	HSStockCode StockCode;
};

///֤ȯ�����ѯӦ��
struct CHSSecuRspQryStkcodeField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ����
	HSStockName	StockName;
	///���뵥λ
	HSNum BuyUnit;
	///��С�۲�(��)
	HSNum PriceStep;
	///��ŵ�λ
	HSNum StoreUnit;
	///�����������
	HSVolume MaxVolume;
	///�����������
	HSVolume MinVolume;
	///֤ȯ���
	HSStockType StockType;
	///��ֵ
	HSPrice ParValue;
	///֤ȯ����
	HSSubStockType SubStockType;
	///������߽��
	HSBalance MaxBalance;	
	///�������ٽ��
	HSBalance MinBalance;
	///֤ȯ״̬
	HSStatus StockCodeStatus;
	///���б�־
	HSDelistFlag DelistFlag;
	//���޼�
	HSPrice UpPrice;
	//���޼�
	HSPrice DownPrice;	
};

///����֤ȯ��Ϣ��ѯ����
struct CHSSecuReqQryCreditCollateralField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
};
///����֤ȯ��Ϣ��ѯӦ��
struct CHSSecuRspQryCreditCollateralField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ����
	HSStockName StockName;
	///֤ȯ���
	HSStockType StockType;
	///��������
	HSDate CollateralEndDate;
	///����������
	HSRate CollateralRate;
	///����״̬
	HSCollateralStatus CollateralStatus;
};

///���֤ȯ��ѯ����
struct CHSSecuReqQryCreditUnderlyingField
{
    ///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
};
///���֤ȯ��ѯӦ��
struct CHSSecuRspQryCreditUnderlyingField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ����
	HSStockName StockName;
	///֤ȯ���
	HSStockType StockType;
	///���ʱ�ĵ�����
	HSDate MarginBuyEndDate;
	///��ȯ��ĵ�����
	HSDate ShortSellEndDate;
	///����״̬
	HSCollateralStatus MarginBuyStatus;
	///��ȯ״̬
	HSCollateralStatus ShortSellStatus;
	///���ʱ�֤�����
	HSRate MarginBuyRate;
	///��ȯ��֤�����
	HSRate ShortSellRate;
};
///ETF������Ϣ��ѯ
struct CHSSecuReqQryEtfcodeField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode EtfCode;
	///�������
	HSStockCode PurRedStockCode;
};
///ETF������Ϣ��ѯӦ��
struct CHSSecuRspQryEtfcodeField
{
	///����������
	HSExchangeID ExchangeID;
	///ETF����
	HSStockCode EtfCode;
	///�������
	HSStockCode PurRedStockCode;
	///����ֽ��������
	HSRate MaxCashRatio;
	///ETF״̬
	HSEtfStatus EtfStatus;
	///T-1���깺��׼��λ�ֽ����
	HSBalance YdCashComponent;
	///T-1���깺��׼��λ��ֵ
	HSBalance YdNavPercu;
	///T-1�ջ���λ��ֵ
	HSPrice	YdNav;
	///ETF���
	HSEtfType EtfType;
	///�깺�ݶ�����
	HSVolume PurchaseMax;
	///��طݶ�����
	HSVolume RedeemMax;
};
///ETF�ɷֹ���Ϣ��ѯ����
struct CHSSecuReqQryEtfcomponentField
{
	///����������
	HSExchangeID ExchangeID;
	///�������
	HSStockCode PurRedStockCode;
	///ETF�ɷֹɴ���
	HSStockCode EtfComponentCode;
};
///ETF�ɷֹ���Ϣ��ѯӦ��
struct CHSSecuRspQryEtfcomponentField
{
	///����������
	HSExchangeID ExchangeID;
	///�������
	HSStockCode PurRedStockCode;
	///ETF�ɷֹɴ���
	HSStockCode EtfComponentCode;
	///�ɷݹ�����
	HSStockName EtfComponentName;
	///�ɷݹ�����
	HSVolume EtfComponentVolume;
	///�����־
	HSFlag ReplaceFlag;
	///��۱���
	HSRate PremiumRate;
	///������
	HSBalance ReplaceBalance;
	///�ɷ��г�
	HSExchangeID EtfComponentMarket;
};

///������ȯ���ʲ�ѯ����
struct CHSSecuReqQryCreditRateField
{
};

///������ȯ���ʲ�ѯ����Ӧ��
struct CHSSecuRspQryCreditRateField
{
	///֤ȯ����
	HSStockCode StockCode;
	///�������
	HSCreditRateType CreditRateType;
	///������
	HSRate YearRate;
};

///�����ʲ���Ϣ��ѯ����
struct CHSSecuReqQryCreditAssetField
{
};
///�����ʲ���Ϣ��ѯӦ��
struct CHSSecuRspQryCreditAssetField
{
	///�ֽ��ʲ�
	HSBalance CashAsset;
	///֤ȯ��ֵ
	HSBalance MarketValue;
	///�����ʲ�
	HSBalance CollateralAsset;
	///��ծ�ܶ�
	HSBalance TotalDebit;
	///����ά�ֵ�������
	HSRisk PerCollateralRatio;
	///���ñ�֤��
	HSBalance AvailableMargin;
	///���ñ�֤��
	HSBalance UsedMargin;
	///���ʶ������
	HSBalance MarginBuyQuota;
	///���ʿ��ö��
	HSBalance MarginBuyAvailableQuota;
	///���ʺ�Լ���
	HSBalance MarginBuyCompactBalance;
	///���ʺ�Լ����
	HSBalance MarginBuyCompactFare;
	///���ʺ�Լ��Ϣ
	HSBalance MarginBuyCompactInterest;
	///���ʺ�Լӯ��
	HSBalance MarginBuyProfit;
	///��ȯ�������
	HSBalance ShortSellQuota;
	///��ȯ���ö��
	HSBalance ShortSellAvailableQuota;
	///��ȯ��Լ���
	HSBalance ShortSellCompactBalance;
	///��ȯ��Լ����
	HSBalance ShortSellCompactFare;
	///��ȯ��Լ��Ϣ
	HSBalance ShortSellCompactInterest;
	///��ȯ��Լӯ��
	HSBalance ShortSellProfit;
	///��ȯ��������ʣ����
	HSBalance SloSurplusBalance;
	///��ȯ����������ʹ�ý��
	HSBalance SloUsedBalance;
};

///�ֽ𻹿�����
struct CHSSecuReqCashRepayField
{
	///��Լ���
	HSCompactID CompactID;
	///ͷ������
	HSCashGroupProp CashGroupProp;
	///������
	HSBalance RepayBalance;
};
///�ֽ𻹿�Ӧ��
struct CHSSecuRspCashRepayField
{
	///�������
	HSBalance OccurBalance;
};

///���ں�Լ��Ϣ��ѯ����
struct CHSSecuReqQryCompactField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode	StockCode;
	///��Լ���
	HSCompactID CompactID;
	///��Լ���
	HSCompactType CompactType;
	///��Լ��Դ
	HSCompactSource CompactSource;
};

///���ں�Լ��Ϣ��ѯӦ��
struct CHSSecuRspQryCompactField
{
	///��������
	HSDate OpenDate;
	///��Լ���
	HSCompactID CompactID;
	///�������
	HSCurrencyID CurrencyID;
	///֤ȯ�˺�
	HSStockAccount StockAccount;
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ����
	HSStockName StockName;
	///��֤�����
	HSRate CreditRate;
	///��Լ���
	HSCompactType CompactType;
	///��Լ״̬
	HSCompactStatus CompactStatus;
	///δ����Լ���
	HSBalance LeaveCompactBalance;
	///δ����Լ����
	HSVolume LeaveCompactVolume;
	///δ���Լ����
	HSBalance LeaveCompactFare;
	///δ���Լ��Ϣ
	HSBalance LeaveCompactInterest;
	///��ծ�ܶ�
	HSBalance TotalDebit;
	///������
	HSRate YearRate;
	///�黹��ֹ��
	HSDate RetEndDate;
	///��Լ��Դ
	HSCompactSource CompactSource;
	///���ʺ�Լӯ��
	HSBalance MarginBuyProfit;
	///��ȯ��Լӯ��
	HSBalance ShortSellProfit;
	///��Ϣ��ʼ����
	HSDate FineBeginDate;
	///�ѻ���Ϣ
	HSBalance RepaidInterest;
	///�ѻ���Լ���
	HSBalance RepaidBalance;
	///�ѻ���Լ����
	HSVolume RepaidAmount;
};

///��Ѻ���ծȯ��ϸ��ѯ����
struct CHSSecuReqQryImpawnDetailField
{
	///֤ȯ�˺�
	HSStockAccount StockAccount;
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;

};

///��Ѻ���ծȯ��ϸ��ѯӦ��
struct CHSSecuRspQryImpawnDetailField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ�˺�
	HSStockAccount StockAccount;
	///֤ȯ����
	HSStockCode StockCode;
	///�������������
	HSVolume StoreVolume;
	///��Ѻ����
	HSPrice ImpawnRate;
	///�����ڼ��������
	HSVolume ImpawnOutVolume;
	///�����ڼ��������
	HSVolume ImpawnInVolume;
	///��Ѻ����
	HSVolume ImpawnVolume;
};

///ծȯ��⼯�жȲ�ѯ����
struct CHSSecuReqQryBondImpawnConcField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
};

///ծȯ��⼯�жȲ�ѯӦ��
struct CHSSecuRspQryBondImpawnConcField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ����
	HSStockName StockName;
	///��Ѻ����
	HSVolume ImpawnVolume;
	///�г��й���
	HSBalance TrusteeVolume;
	///ծȯ��⼯�ж�
	HSRate BondConcRatio;
	///���ж�ʣ����������
	HSVolume ConcSurplusVolume;
};

//��ϱ���¼��
struct CHSSecuReqComOrderInsertField
{
	//������Ϣ��������ReqOrder������ЧԪ�ظ�������ЧԪ�ش�ReqOrder[0] ~ ReqOrder[Count-1]
	HSNum Count;
	//������Ϣ
	CHSSecuReqOrderInsertField ReqOrder[1000];
};

//��ϱ���¼��Ӧ��
struct CHSSecuRspComOrderInsertField
{
	//����Ӧ����Ϣ��������RspOrder������ЧԪ�ظ���������ϱ���¼�������Countһ�£�����ЧԪ�ش�RspOrder[0] ~ RspOrder[Count-1]
	HSNum Count;
	//����Ӧ����Ϣ���飨����ϱ���¼����ı�����Ϣһһ��Ӧ����Ҫ�������Ӧ����Ϣ���жϱ����Ƿ�ɹ���
	CHSSecuRspOrderInsertField RspOrder[1000];
};

//���Ӧ����Ϣ
struct CHSSecuRspComInfoField
{
	//Ӧ����Ϣ��������RspInfo������ЧԪ�ظ���������ϱ���¼�������Countһ�£�����ЧԪ�ش�RspInfo[0] ~ RspInfo[Count-1]
	HSNum Count;
	//Ӧ����Ϣ���飨����ϱ���¼����ı�����Ϣһһ��Ӧ������Ӧ����Ϣ�������ж�ÿ�ʱ����Ƿ�ɹ�������ɹ�������Դ���ϱ���¼��Ӧ�����ȡ����Ӧ����Ϣ��
	CHSSecuRspInfoField RspInfo[1000];
};

///��Լչ����������
struct CHSSecuReqCompactApplyField
{
	///��Լ��Ŵ���ÿ����Լ�Զ��ŷָ���
	HSCompactIDStr CompactIDStr;
};

///��Լչ������Ӧ��
struct CHSSecuRspCompactApplyField
{

};

///�¹��깺�����ѯ����
struct CHSSecuReqQryApplycodeField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ����
	HSSubStockType SubStockType;
};

///�¹��깺�����ѯӦ��
struct CHSSecuRspQryApplycodeField
{
	///����������
	HSExchangeID ExchangeID;
	///֤ȯ����
	HSStockCode StockCode;
	///֤ȯ����
	HSStockName	StockName;
	///���뵥λ
	HSNum BuyUnit;
	///��С�۲�(��)
	HSNum PriceStep;
	///��ŵ�λ
	HSNum StoreUnit;
	///�����������
	HSVolume MaxVolume;
	///�����������
	HSVolume MinVolume;
	///֤ȯ���
	HSStockType StockType;
	///��ֵ
	HSPrice ParValue;
	///֤ȯ����
	HSSubStockType SubStockType;
	///������߽��
	HSBalance MaxBalance;
	///�������ٽ��
	HSBalance MinBalance;
	///֤ȯ״̬
	HSStatus StockCodeStatus;
	///��������
	HSDate IssueDate;
};


///�ʽ���ˮ��ѯ
struct CHSSecuReqQryFundRealJourField
{
	///�������
	HSCurrencyID CurrencyID;
};

///�ʽ���ˮ��ѯӦ��
struct CHSSecuRspQryFundRealJourField
{
	///��ˮ���
	HSNum		    SerialNo;
	///�������
	HSCurrencyID 	CurrencyID;
	///�������
	HSBalance 		OccurBalance;
	///���ʽ��
	HSBalance		PostBalance;
	///���ױ䶯����
	HSRealActionType		RealAction;
	///ҵ���־
	HSBusinessFlag		    BusinessFlag;
	///��ǰʱ��
	HSTime					CurrTime;
};

///ʵʱ��Լ��ˮ��ѯ
struct CHSSecuReqQryCompactRealJourField
{
	///֤ȯ����
	HSStockCode					StockCode;
	///��Լ��Դ
	HSCompactSource             CompactSource;
	///��Լ���
	HSCompactType               CompactType;
	///��Լ���
	HSCompactID                 CompactID;
	///���͹�˾��������
    HSBrokerOrderID 			BrokerOrderID;
};
    
///ʵʱ��Լ��ˮ��ѯӦ��
struct CHSSecuRspQryCompactRealJourField
{
	///֤ȯ�˺�
	HSStockAccount              StockAccount;
	///����
	HSCurrencyID                CurrencyID;
	///�ʲ��˺�
	HSAccountID                 AccountID;
	///�������
	HSExchangeID                ExchangeType;
	///��ˮ���
	HSNum		    			SerialNo;
	///��ǰ����
	HSDate                      CurrDate;
	///��ǰʱ��
	HSTime                      CurrTime;
	///ҵ���־
	HSBusinessFlag              BusinessFlag;
	///�������
	HSBalance                   OccurBalance;
	///���ʽ��
	HSBalance                   PostBalance;
	///��������
	HSVolume                    OccurAmount;
	///��֤ȯ��
	HSVolume                    PostAmount;
	///��������
	HSBalance                   OccurFare;
	///�������
	HSBalance                   PostFare;
	///������Ϣ
	HSBalance                   OccurInterest;
	///������Ϣ
	HSBalance                   PostInterest;
	///���͹�˾��������
    HSBrokerOrderID 			BrokerOrderID;
	///��Լ���
	HSCompactID                 CompactID;
	///֤ȯ����
	HSStockCode                 StockCode;
};

///������������ȡ����
struct CHSSecuReqQryMaxEntradeNumField
{
	/// ����������
	HSExchangeID 					ExchangeID;
	/// ֤ȯ����
	HSStockCode    			        StockCode; 
    /// ����ָ��
	HSOrderCommand				  	OrderCommand;
    /// ��������
    HSOrderDirection              	Direction;
    /// �����۸�
    HSPrice                       	OrderPrice;
    /// ͷ������
	HSCashGroupProp               	CashGroupProp;
};

///������������ȡӦ��
struct CHSSecuRspQryMaxEntradeNumField
{
	/// ����������
    HSVolume                        AvailableTradeAmount;
	/// �����ʽ�
	HSBalance                       AvailableBalance;
};

///�ɷ���ˮ��ѯ
struct CHSSecuReqQryStockRealJourField
{
	///����������
	HSExchangeID 		ExchangeID;
	///֤ȯ����
	HSStockCode 		StockCode;
};

///�ɷ���ˮ��ѯӦ��
struct CHSSecuRspQryStockRealJourField
{
	  ///����������
	HSExchangeID 		ExchangeID;
	///֤ȯ����
	HSStockCode 		StockCode;
	///֤ȯ����
	HSStockName  		StockName;
	///֤ȯ���
	HSStockType  		StockType;
	///��ˮ���
	HSNum    			SerialNo;
	///��������
	HSVolume    		OccurVolume;
	///��������
	HSVolume    		PostVolume;
	///���ױ䶯����
	HSRealActionType	RealAction;
	///ҵ���־
	HSBusinessFlag		BusinessFlag;
	///֤ȯ�˺�
	HSStockAccount		StockAccount;
};

///�����˻���ѯ
struct CHSSecuReqQryBankAccountField
{
    /// ���д���
    HSBankID                      BankID;
    /// ����
    HSCurrencyID                  CurrencyID;
};

///�����˻���ѯӦ��
struct CHSSecuRspQryBankAccountField
{
    /// ���д���
    HSBankID                      BankID;
    /// ��������
    HSBankName                    BankName;
    /// �����˺�
    HSBankAccountID               BankAccountID;
    /// ����
    HSCurrencyID                  CurrencyID;
};

///�۹�ͨ�ͻ����˽��׻��ʲ�ѯ����
struct CHSSecuReqQryHKSecurateField
{
	/// ����������
	HSExchangeID                ExchangeID;
};

///�۹�ͨ�ͻ����˽��׻��ʲ�ѯӦ��
struct CHSSecuRspQryHKSecurateField
{
	/// ������ʣ����ϸ������ʺ�ģ�
	HSRate				BuyExchangeRate;
	/// �������ʣ����ϸ������ʺ�ģ�
	HSRate				SellExchangeRate;
	/// �м����
	HSRate				MiddleExchangeRate;
	/// �������������
	HSRate				SeBuyExchangeRate;
	/// ��������������
	HSRate				SeSellExchangeRate;
	/// ���븡������
	HSRate				BuyFloatRatio;
	/// ������������
	HSRate				SellFloatRatio;
	/// ����������
	HSExchangeID		ExchangeID;
	/// ��Ч����
	HSDate				ValidDate;
};

///�����ύ֤ȯ����������ѯ����
struct CHSSecuReqQryAssureAmountField
{
	///֤ȯ����
	HSStockCode	StockCode;
	///����������
	HSExchangeID ExchangeID;
};

///�����ύ֤ȯ����������ѯӦ��
struct CHSSecuRspQryAssureAmountField
{
	///��������
	HSVolume 	EnableAmount;
};

///����֤ȯ�ɷ���������ѯ����
struct CHSSecuReqQryAssureBackAmountField
{
	///�������
	HSExchangeID					ExchangeID;
	///֤ȯ����
	HSStockCode						StockCode;
};

///����֤ȯ�ɷ���������ѯӦ��
struct CHSSecuRspQryAssureBackAmountField
{
	///�������
	HSExchangeID	ExchangeID;
	///֤ȯ����
	HSStockCode		StockCode;
	///���Ի�ȯ����
	HSVolume		EnableReturnAmount;
};

///�Զ˿��ٽ��������ʽ��ѯ
struct CHSSecuReqQryFundPeerField
{
	///	�Զ˿��ٽ��׽ڵ�ţ�˫����ģʽ�£�����0��API�����л�ȡ��ȷ�ڵ�ţ�����������ģʽ�£�������ұ������0��
	HSSysnodeID			SysnodeID;
	///	�������
	HSCurrencyID		CurrencyID;
};

///�Զ˿��ٽ��������ʽ��ѯӦ��
struct CHSSecuRspQryFundPeerField
{
	///	��ǰ���
	HSBalance			CurrentBalance;
	///	�����ʽ�
	HSBalance			AvailableBalance;
	///	�������
	HSCurrencyID		CurrencyID;
};
//#pragma pack(pop)
#endif
