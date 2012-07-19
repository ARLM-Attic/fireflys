//
//  Shader.fsh
//  Fireflys
//
//  Created by Adrian on 12-7-18.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
