/*
 *  Form.h
 *  Fireflys
 *
 *  Created by Adrian on 12-8-2.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __FORM_H__
#define __FORM_H__

#include "Define.h"

namespace Fireflys
{

	class FF_API Form
	{
	public:
		virtual void OnInit();
		virtual void OnDestroy();
	};
	
}

#endif // __FORM_H__

