#pragma once
#include <vector>
#include <string>
#include "HSSecuTradeApi.h"


struct HsDict
{
	std::string HsConstName;
	std::string HsDictValue;
	std::string HsDictPrompt;
};

class ApiUtility {
public:
	static TRADE_API_EXPORT ApiUtility* NewApiUtility(CHSSecuTradeApi* tradeApi);

	#pragma region �����ֵ�
	///��ȡ������׼�ֶε�����
	virtual void GetFieldPrompt(std::string& fieldPrompt, std::string fieldName) = 0;

	///��ȡ������׼�ֶε��ֵ����
	virtual void GetDictInfoByFieldName(std::vector<HsDict>& dictVector, std::string fieldName) = 0;
	
	///��ȡfieldName��HsDictValue��Ӧ���ֵ�������
	virtual void GetDictInfoByFieldName(std::string& dictPrompt, std::string fieldName, std::string dictValue) = 0;

	///��ȡfieldName��HsDictValue��Ӧ���ֵ�������
	virtual void GetDictInfoByFieldName(std::string& dictPrompt, std::string fieldName, char dictValue) = 0;

	///��ȡfieldName��HsDictValue��Ӧ���ֵ�������
	virtual void GetDictInfoByFieldName(std::string& dictPrompt, std::string fieldName, int dictValue) = 0;

	///��ȡfieldName��HsDictValue��Ӧ���ֵ�������
	virtual void GetDictInfoByFieldName(std::string& dictPrompt, std::string fieldName, double dictValue) = 0;

	#pragma endregion

	#pragma region ����
	///��ȡ�ṹ���index���ṹ���ֶ�����,���õ�FieldName��,index��0��ʼ.���±곬�޻�structName���Ϸ�����������ֵС��0
	virtual int GetAPIStructFieldName(const char* structName, int index, std::string& FieldName) = 0;
	
	///��ȡstructAddr�ṹ������е�index���ṹ���ֶε�ֵ,���õ�FieldValue��,index��0��ʼ.���±곬�޻�structName���Ϸ�����������ֵС��0
	virtual int GetAPIStructFieldValueByIndex(const char* structName, void* structAddr, int index, std::string& fieldValue) = 0;

	///��ȡstructAddr�ṹ�����������Ϊ��fieldName���ֶε�ֵ,���õ�FieldValue��,���ֶβ����ڻ�structName���Ϸ�����������ֵС��0
	virtual int GetAPIStructFieldValueByName(const char* structName, void* structAddr, const char* fieldName, std::string& fieldValue) = 0;

	///��ȡ�ṹ���ֶ�����.��structName���Ϸ�����������ֵС��0
	virtual int GetAPIStructFieldCounts(const char* structName) = 0;
	#pragma endregion

protected:
	~ApiUtility() {};
	ApiUtility() {};
};

extern   "C"
{
	/// Description: ����������ӿ�    
	/// Input      : tradeApi    apiʵ��   
	TRADE_API_EXPORT ApiUtility* NewApiUtility(CHSSecuTradeApi* tradeApi);
}
