/*
 * License Agreement 
 *
 * Copyright (c) 2007, 2008, 2009 Advanced Micro Devices Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in any form of this material and any product thereof including
 * software in source or binary forms, along with any related documentation, with or 
 * without modification ("this material"), is permitted provided that the following 
 * conditions are met:
 *
 *    + Redistributions of source code of any software must retain the above copyright 
 *      notice and all terms of this license as part of the code.
 *
 *    + Redistributions in binary form of any software must reproduce the above copyright 
 *      notice and all terms of this license in any related documentation and/or other 
 *      materials.
 *
 *    + Neither the names nor trademarks of Advanced Micro Devices, Inc. or any copyright 
 *      holders or contributors may be used to endorse or promote products derived from 
 *      this material without specific prior written permission.
 *
 *    + Notice about U.S. Government restricted rights: This material is provided with ?
 *      RESTRICTED RIGHTS.? Use, duplication or disclosure by the U.S. Government is subject 
 *      to the full extent of restrictions set forth in FAR52.227 and DFARS252.227 et seq., 
 *      or any successor or applicable regulations. Use of this material by the U.S. 
 *      Government constitutes acknowledgment  of  the  proprietary rights of 
 *      Advanced Micro Devices, Inc. and any copyright holders and contributors. 
 *
 *    + In no event shall anyone redistributing or accessing or using this material 
 *      commence or participate in any arbitration or legal action relating to this 
 *      material against Advanced Micro Devices, Inc. or any copyright holders or contributors. 
 *      The foregoing shall survive any expiration or termination of this license or any 
 *      agreement or access or use related to this material.  
 *
 *    + ANY BREACH OF ANY TERM OF THIS LICENSE SHALL RESULT IN THE IMMEDIATE REVOCATION 
 *      OF ALL RIGHTS TO REDISTRIBUTE, ACCESS OR USE THIS MATERIAL. 
 *
 * THIS MATERIAL IS PROVIDED BY ADVANCED MICRO DEVICES, INC. AND ANY COPYRIGHT HOLDERS AND 
 * CONTRIBUTORS "AS IS" IN ITS CURRENT CONDITION AND WITHOUT ANY REPRESENTATIONS, GUARANTEE, 
 * OR WARRANTY OF ANY KIND OR IN ANY WAY RELATED TO SUPPORT, INDEMNITY, ERROR FREE OR 
 * UNINTERRUPTED OPERATION, OR THAT IT IS FREE FROM DEFECTS OR VIRUSES.  ALL OBLIGATIONS 
 * ARE HEREBY DISCLAIMED - WHETHER EXPRESS, IMPLIED, OR STATUTORY - INCLUDING, BUT NOT 
 * LIMITED TO, ANY IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE, ACCURACY, COMPLETENESS, OPERABILITY, QUALITY OF SERVICE, OR NON-INFRINGEMENT. 
 * IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. OR ANY COPYRIGHT HOLDERS OR CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, REVENUE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * OR BASED ON ANY THEORY OF LIABILITY ARISING IN ANY WAY RELATED TO THIS MATERIAL, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. THE ENTIRE AND AGGREGATE LIABILITY OF ADVANCED 
 * MICRO DEVICES, INC. AND ANY COPYRIGHT HOLDERS AND CONTRIBUTORS SHALL NOT EXCEED TEN DOLLARS 
 * (US $10.00). ANYONE REDISTRIBUTING OR ACCESSING OR USING THIS MATERIAL ACCEPTS THIS 
 * ALLOCATION OF RISK AND AGREES TO RELEASE ADVANCED MICRO DEVICES, INC. AND ANY COPYRIGHT 
 * HOLDERS AND CONTRIBUTORS FROM ANY AND ALL LIABILITIES, OBLIGATIONS, CLAIMS, OR DEMANDS IN 
 * EXCESS OF TEN DOLLARS (US $10.00). THE FOREGOING ARE ESSENTIAL TERMS OF THIS LICENSE AND, 
 * IF ANY OF THESE TERMS ARE CONSTRUED AS UNENFORCEABLE, FAIL IN ESSENTIAL PURPOSE, OR BECOME 
 * VOID OR DETRIMENTAL TO ADVANCED MICRO DEVICES, INC. OR ANY COPYRIGHT HOLDERS OR CONTRIBUTORS 
 * FOR ANY REASON, THEN ALL RIGHTS TO REDISTRIBUTE, ACCESS OR USE THIS MATERIAL SHALL TERMINATE 
 * IMMEDIATELY. MOREOVER, THE FOREGOING SHALL SURVIVE ANY EXPIRATION OR TERMINATION OF THIS 
 * LICENSE OR ANY AGREEMENT OR ACCESS OR USE RELATED TO THIS MATERIAL. 
 *
 * NOTICE IS HEREBY PROVIDED, AND BY REDISTRIBUTING OR ACCESSING OR USING THIS MATERIAL SUCH NOTICE 
 * IS ACKNOWLEDGED, THAT THIS MATERIAL MAY BE SUBJECT TO RESTRICTIONS UNDER THE LAWS AND REGULATIONS 
 * OF THE UNITED STATES OR OTHER COUNTRIES, WHICH INCLUDE BUT ARE NOT LIMITED TO, U.S. EXPORT 
 * CONTROL LAWS SUCH AS THE EXPORT ADMINISTRATION REGULATIONS AND NATIONAL SECURITY CONTROLS AS 
 * DEFINED THEREUNDER, AS WELL AS STATE DEPARTMENT CONTROLS UNDER THE U.S. MUNITIONS LIST. THIS 
 * MATERIAL MAY NOT BE USED, RELEASED, TRANSFERRED, IMPORTED, EXPORTED AND/OR RE-EXPORTED IN ANY 
 * MANNER PROHIBITED UNDER ANY APPLICABLE LAWS, INCLUDING U.S. EXPORT CONTROL LAWS REGARDING 
 * SPECIFICALLY DESIGNATED PERSONS, COUNTRIES AND NATIONALS OF COUNTRIES SUBJECT TO NATIONAL SECURITY 
 * CONTROLS. MOREOVER, THE FOREGOING SHALL SURVIVE ANY EXPIRATION OR TERMINATION OF ANY LICENSE 
 * OR AGREEMENT OR ACCESS OR USE RELATED TO THIS MATERIAL. 
 *
 * This license forms the entire agreement regarding the subject matter hereof and supersedes all 
 * proposals and prior discussions and writings between the parties with respect thereto. This 
 * license does not affect any ownership, rights, title, or interest in, or relating to, this 
 * material. No terms of this license can be modified or waived, and no breach of this license 
 * can be excused, unless done so in a writing signed by all affected parties. Each term of this 
 * license is separately enforceable. If any term of this license is determined to be or becomes 
 * unenforceable or illegal, such term shall be reformed to the minimum extent necessary in order 
 * for this license to remain in effect in accordance with its terms as modified by such reformation. 
 * This license shall be governed by and construed in accordance with the laws of the State of 
 * Texas without regard to rules on conflicts of law of any state or jurisdiction or the United 
 * Nations Convention on the International Sale of Goods. All disputes arising out of this license 
 * shall be subject to the jurisdiction of the federal and state courts in Austin, Texas, and all 
 * defenses are hereby waived concerning personal jurisdiction and venue of these courts.
 */
/**
 * ciminstance.h
 * A Class representing a CIM Instance.
 */
#ifndef __DSDK_CIMINSTANCE_H__
#define __DSDK_CIMINSTANCE_H__
#include <cmci/cmci.h>
#include <string>
#include <vector>
#include <dsdk/cim/cimerror.h>
#include <dsdk/cim/cimdata.h>
#include <dsdk/cim/cimobjectpath.h>

using std::string;
using std::vector;

namespace dsdk
{

/**
 * @class CCIMInstance
 * @brief A Class representing an CIM Instance.
 */
class DSDK_Export CCIMInstance
{
public:
	/**
	 * Construct a CIM Instance from the object path 
	 */
	CCIMInstance (const CCIMObjectPath& op);

	/**
	 * Convert the low level Instance to CCIMInstance. The low level 
	 * Instance should not be released or assigned to another object after
	 * this call. We could have cloned this low level object path 
	 * but this would incur an unnecessary memory allocation since most 
	 * of the use cases will be just a straight conversion from low level 
	 * Instance.
	 */
	static CCIMInstance toCCIMInstance (CMPIInstance* inst,
										bool auto_release = true);

	/**
	 * Returns a null instance. This instance cannot be used for any 
	 * operations, but to act as a place holder for the creation of 
	 * upper layer objects.
	 */
	static CCIMInstance nullInstance (void) { return CCIMInstance (); }

public:
	/**
	 * Copy constructor
	 */
	CCIMInstance (const CCIMInstance& cls) throw (ECIMError);

	/**
	 * Assignment operator.
	 */
	const CCIMInstance& operator = (const CCIMInstance& rhs)
													throw (ECIMError);

public:
	/**
	 * Destructor
	 */
	~CCIMInstance ();
	

public:
	/**
	 * Clone this object.
	 */
	CCIMInstance* clone (void) throw (ECIMError);

	/**
	 * Gets a named property value.
	 */
	CCIMData getProperty (const string& name) const throw (ECIMError);

	/**
	 * Gets the number of properties contained in this instance.
	 */
	unsigned int getPropertyCount (void) const throw (ECIMError);

	/**
	 * Gets a property value defined by its index.
	 */
	CCIMData getPropertyAt (unsigned int index, string* name) 
												const throw (ECIMError);

	/**
	 * Adds / replace a named property.
	 */
	void setProperty (const string& name, const CCIMValue& value) throw (ECIMError);

	/**
	 * Directs the low level layer to ignore any setProperty operations 
	 * for this instance for any properties not in this list.
	 */
	void setPropertyFilter (const vector<string>& props, 
							const vector<string>& keys) throw (ECIMError);

	/** 
	 * Gets the qualifier.
	 */
	CCIMData getQualifier (const string& name) const throw (ECIMError);

	/**
	 * Gets the qualifier count.
	 */
	unsigned int getQualifierCount (void) const throw (ECIMError);

	/**
	 * Gets the qualifier at the index.
	 */
	CCIMData getQualifierAt (unsigned int index, string* name) 
												const throw (ECIMError); 

	/**
	 * Gets the property qualifier.
	 */
	CCIMData getPropertyQualifier (const string& pname, const string& qname);

	/** 
	 * Gets the property qualifier count.
	 */
	unsigned int getPropertyQualifierCount (const string& pname) const throw (ECIMError);

	/**
	 * Gets the property qualify at the specified index.
	 */
	CCIMData getPropertyQualifierAt (const string& pname, unsigned int index,
										string* qname) const throw (ECIMError);

public:
	/**
	 * Returns the low level instance.
	 */
	CMPIInstance* getLowLevelObject (void) const { return _inst; }

	/*
	 * The object path of the low level function does not contain the 
	 * namespace component, due to some bug in sfcc. The following functions
	 * allow us to store and retrieve the object path, seperately. By default 
	 * the object path matches the low level instance returned object path.
	 */

	/**
	 * Generates an object path out of the namespace, classname and key
	 * properties of this instance.
	 */
	CCIMObjectPath getObjectPath (void) const throw (ECIMError);

	/**
	 * Sets the object path corresponding to this instance.
	 */
	void setObjectPath (const CCIMObjectPath& op);

	/**
	 * Construct the object path using class/key properties table
	 */
	friend void DSDK_Export makeInstanceObjectPath (CCIMInstance* inst, const string& classname);	

public:
	typedef CIterator<CKeyClass<CCIMInstance> > iterator;

public:
	/**
	 * Default constructor
	 */
	CCIMInstance () : _op_set (false), _null_inst (true) { /* Empty */ }

public:
	/*--------- CCIMValue Conversion adapter required functions ----------*/
	typedef CCIMInstance AdapteeType;
    static const CMPIType 	cmpi_type = CMPI_instance;

	/**
	 * Creates this object from a string. This is not supported.
	 */
    static CCIMInstance create (string /* val_str */) 
    { 
    	throw (EInvalidValueObject (CMPI_string));
    }

	/**
	 * Creates this object from a low level CMPIValue.
	 */
    static CCIMInstance create (CMPIValue* val, bool auto_release)         
    {                                                                       
        return toCCIMInstance (val->inst, auto_release);
    }

	/**
	 * Converts @p val to a low level CMPIValue object.
	 */
	static CMPIValue toCMPIValue (CCIMInstance val) 
    {                                                                       
        CMPIValue cv;                                                       
        cv.inst = val.getLowLevelObject ();                                                   
		return cv;															
    }          
	/*------------ End of CCIMConversion adapter functions ---------------*/
                                                                            
private:
	/**
	 * Build a CCIMInstance from the low level instance.
	 */
	CCIMInstance (CMPIInstance* inst) : _inst (inst), 
										_op_set (false) { /* Empty */ }

private:
	CMPIInstance*	_inst;
	CCIMObjectPath*	_op;
	bool			_op_set;
	int*			_ref_count;
	bool			_auto_release;
	bool			_null_inst;
};


/**
 * Convert a CIM value to a CCIMInstance. 
.* Based on the CIMValue type passed to us we either create an instance 
 * from the lower level instance or create it from the lower level objectpath
 */
template <>
inline CCIMInstance
to<CCIMInstance> (CCIMValue& cv, bool auto_release)
{
	CMPIType   cmpi_type = cv.getLowLevelType ();
	CMPIValue* cmpi_val  = cv.getLowLevelValue ();

	if (cmpi_type == CMPI_instance)
	{
		if (auto_release) { cv.invalidate (); }
		return CCIMInstance::create (cmpi_val, auto_release);
	}
	if (cmpi_type == CMPI_ref)
	{
		CCIMObjectPath	op = CCIMObjectPath::toCCIMObjectPath (cmpi_val->ref, auto_release);
		return CCIMInstance	(op);
	}
	else { throw (EInvalidValueObject (cmpi_type)); }
}


}; /* namespace dsdk */

#endif /* __DSDK_CIMINSTANCE_H__ */
