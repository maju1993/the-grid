//////////////////////////////////////////////////////////////////////
// (c) Janusz Ganczarski
// http://www.januszg.hg.pl
// JanuszG@enter.net.pl
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "extensions3.h"

//////////////////////////////////////////////////////////////////////
// obs≥uga rozszerzeÒ w systemach Windows
//////////////////////////////////////////////////////////////////////
#ifdef WIN32

//////////////////////////////////////////////////////////////////////
// wskaünik funkcji pochodzπcej z rozszerzenia WGL_ARB_create_context
//////////////////////////////////////////////////////////////////////
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 1.2
//////////////////////////////////////////////////////////////////////
PFNGLBLENDCOLORPROC glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glBlendEquation = NULL;
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = NULL;
PFNGLTEXIMAGE3DPROC glTexImage3D = NULL;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = NULL;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 1.3
//////////////////////////////////////////////////////////////////////
PFNGLACTIVETEXTUREPROC glActiveTexture = NULL;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 1.4
//////////////////////////////////////////////////////////////////////
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = NULL;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = NULL;
PFNGLPOINTPARAMETERFPROC glPointParameterf = NULL;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv = NULL;
PFNGLPOINTPARAMETERIPROC glPointParameteri = NULL;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 1.5
//////////////////////////////////////////////////////////////////////
PFNGLGENQUERIESPROC glGenQueries = NULL;
PFNGLDELETEQUERIESPROC glDeleteQueries = NULL;
PFNGLISQUERYPROC glIsQuery = NULL;
PFNGLBEGINQUERYPROC glBeginQuery = NULL;
PFNGLENDQUERYPROC glEndQuery = NULL;
PFNGLGETQUERYIVPROC glGetQueryiv = NULL;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = NULL;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = NULL;
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
PFNGLGENBUFFERSPROC glGenBuffers = NULL;
PFNGLISBUFFERPROC glIsBuffer = NULL;
PFNGLBUFFERDATAPROC glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC glBufferSubData = NULL;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = NULL;
PFNGLMAPBUFFERPROC glMapBuffer = NULL;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = NULL;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 2.0
//////////////////////////////////////////////////////////////////////
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = NULL;
PFNGLDRAWBUFFERSPROC glDrawBuffers = NULL;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate = NULL;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate = NULL;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate = NULL;
PFNGLATTACHSHADERPROC glAttachShader = NULL;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = NULL;
PFNGLCOMPILESHADERPROC glCompileShader = NULL;
PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
PFNGLCREATESHADERPROC glCreateShader = NULL;
PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
PFNGLDELETESHADERPROC glDeleteShader = NULL;
PFNGLDETACHSHADERPROC glDetachShader = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = NULL;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = NULL;
PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
PFNGLGETSHADERSOURCEPROC glGetShaderSource = NULL;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
PFNGLGETUNIFORMFVPROC glGetUniformfv = NULL;
PFNGLGETUNIFORMIVPROC glGetUniformiv = NULL;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv = NULL;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv = NULL;
PFNGLISPROGRAMPROC glIsProgram = NULL;
PFNGLISSHADERPROC glIsShader = NULL;
PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
PFNGLSHADERSOURCEPROC glShaderSource = NULL;
PFNGLUSEPROGRAMPROC glUseProgram = NULL;
PFNGLUNIFORM1FPROC glUniform1f = NULL;
PFNGLUNIFORM2FPROC glUniform2f = NULL;
PFNGLUNIFORM3FPROC glUniform3f = NULL;
PFNGLUNIFORM4FPROC glUniform4f = NULL;
PFNGLUNIFORM1IPROC glUniform1i = NULL;
PFNGLUNIFORM2IPROC glUniform2i = NULL;
PFNGLUNIFORM3IPROC glUniform3i = NULL;
PFNGLUNIFORM4IPROC glUniform4i = NULL;
PFNGLUNIFORM1FVPROC glUniform1fv = NULL;
PFNGLUNIFORM2FVPROC glUniform2fv = NULL;
PFNGLUNIFORM3FVPROC glUniform3fv = NULL;
PFNGLUNIFORM4FVPROC glUniform4fv = NULL;
PFNGLUNIFORM1IVPROC glUniform1iv = NULL;
PFNGLUNIFORM2IVPROC glUniform2iv = NULL;
PFNGLUNIFORM3IVPROC glUniform3iv = NULL;
PFNGLUNIFORM4IVPROC glUniform4iv = NULL;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = NULL;
PFNGLVALIDATEPROGRAMPROC glValidateProgram = NULL;
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d = NULL;
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv = NULL;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s = NULL;
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv = NULL;
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d = NULL;
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv = NULL;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s = NULL;
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv = NULL;
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d = NULL;
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv = NULL;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s = NULL;
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv = NULL;
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv = NULL;
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv = NULL;
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv = NULL;
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub = NULL;
PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv = NULL;
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv = NULL;
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv = NULL;
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv = NULL;
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d = NULL;
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv = NULL;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv = NULL;
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv = NULL;
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s = NULL;
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv = NULL;
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv = NULL;
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv = NULL;
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 2.1
//////////////////////////////////////////////////////////////////////
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 3.0
//////////////////////////////////////////////////////////////////////
PFNGLCOLORMASKIPROC glColorMaski = NULL;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v = NULL;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v = NULL;
PFNGLENABLEIPROC glEnablei = NULL;
PFNGLDISABLEIPROC glDisablei = NULL;
PFNGLISENABLEDIPROC glIsEnabledi = NULL;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback = NULL;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback = NULL;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange = NULL;
PFNGLBINDBUFFERBASEPROC glBindBufferBase = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying = NULL;
PFNGLCLAMPCOLORPROC glClampColor = NULL;
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender = NULL;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender = NULL;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer = NULL;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv = NULL;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv = NULL;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv = NULL;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation = NULL;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation = NULL;
PFNGLUNIFORM1UIPROC glUniform1ui = NULL;
PFNGLUNIFORM2UIPROC glUniform2ui = NULL;
PFNGLUNIFORM3UIPROC glUniform3ui = NULL;
PFNGLUNIFORM4UIPROC glUniform4ui = NULL;
PFNGLUNIFORM1UIVPROC glUniform1uiv = NULL;
PFNGLUNIFORM2UIVPROC glUniform2uiv = NULL;
PFNGLUNIFORM3UIVPROC glUniform3uiv = NULL;
PFNGLUNIFORM4UIVPROC glUniform4uiv = NULL;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv = NULL;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv = NULL;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv = NULL;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv = NULL;
PFNGLCLEARBUFFERIVPROC glClearBufferiv = NULL;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = NULL;
PFNGLCLEARBUFFERFVPROC glClearBufferfv = NULL;
PFNGLCLEARBUFFERFIPROC glClearBufferfi = NULL;
PFNGLGETSTRINGIPROC glGetStringi = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_framebuffer_object (OpenGL 3.0)
//////////////////////////////////////////////////////////////////////
PFNGLISRENDERBUFFERPROC glIsRenderbuffer = NULL;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer = NULL;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers = NULL;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers = NULL;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv = NULL;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer = NULL;
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer = NULL;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers = NULL;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus = NULL;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D = NULL;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D = NULL;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D = NULL;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv = NULL;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap = NULL;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample = NULL;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_map_buffer_range (OpenGL 3.0)
//////////////////////////////////////////////////////////////////////
PFNGLMAPBUFFERRANGEPROC glMapBufferRange = NULL;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_vertex_array_object (OpenGL 3.0)
//////////////////////////////////////////////////////////////////////
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = NULL;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = NULL;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = NULL;
PFNGLISVERTEXARRAYPROC glIsVertexArray = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 3.1
//////////////////////////////////////////////////////////////////////
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = NULL;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = NULL;
PFNGLTEXBUFFERPROC glTexBuffer = NULL;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_uniform_buffer_object (OpenGL 3.1)
//////////////////////////////////////////////////////////////////////
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = NULL;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = NULL;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = NULL;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = NULL;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_copy_buffer (OpenGL 3.1)
//////////////////////////////////////////////////////////////////////
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 3.2
//////////////////////////////////////////////////////////////////////
PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = NULL;
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = NULL;
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_draw_elements_base_vertex (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = NULL;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = NULL;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_provoking_vertex (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLPROVOKINGVERTEXPROC glProvokingVertex = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_sync (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLFENCESYNCPROC glFenceSync = NULL;
PFNGLISSYNCPROC glIsSync = NULL;
PFNGLDELETESYNCPROC glDeleteSync = NULL;
PFNGLCLIENTWAITSYNCPROC glClientWaitSync = NULL;
PFNGLWAITSYNCPROC glWaitSync = NULL;
PFNGLGETINTEGER64VPROC glGetInteger64v = NULL;
PFNGLGETSYNCIVPROC glGetSynciv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_texture_multisample (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = NULL;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = NULL;
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = NULL;
PFNGLSAMPLEMASKIPROC glSampleMaski = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 3.3
//////////////////////////////////////////////////////////////////////
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_blend_func_extended (OpenGL 3.3)
//////////////////////////////////////////////////////////////////////
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed = NULL;
PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_sampler_objects (OpenGL 3.3)
//////////////////////////////////////////////////////////////////////
PFNGLGENSAMPLERSPROC glGenSamplers = NULL;
PFNGLDELETESAMPLERSPROC glDeleteSamplers = NULL;
PFNGLISSAMPLERPROC glIsSampler = NULL;
PFNGLBINDSAMPLERPROC glBindSampler = NULL;
PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri = NULL;
PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv = NULL;
PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf = NULL;
PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv = NULL;
PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv = NULL;
PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv = NULL;
PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv = NULL;
PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv = NULL;
PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv = NULL;
PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_timer_query (OpenGL 3.3)
//////////////////////////////////////////////////////////////////////
PFNGLQUERYCOUNTERPROC glQueryCounter = NULL;
PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v = NULL;
PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_vertex_type_2_10_10_10_rev (OpenGL 3.3)
//////////////////////////////////////////////////////////////////////
PFNGLVERTEXP2UIPROC glVertexP2ui = NULL;
PFNGLVERTEXP2UIVPROC glVertexP2uiv = NULL;
PFNGLVERTEXP3UIPROC glVertexP3ui = NULL;
PFNGLVERTEXP3UIVPROC glVertexP3uiv = NULL;
PFNGLVERTEXP4UIPROC glVertexP4ui = NULL;
PFNGLVERTEXP4UIVPROC glVertexP4uiv = NULL;
PFNGLTEXCOORDP1UIPROC glTexCoordP1ui = NULL;
PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv = NULL;
PFNGLTEXCOORDP2UIPROC glTexCoordP2ui = NULL;
PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv = NULL;
PFNGLTEXCOORDP3UIPROC glTexCoordP3ui = NULL;
PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv = NULL;
PFNGLTEXCOORDP4UIPROC glTexCoordP4ui = NULL;
PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv = NULL;
PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui = NULL;
PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv = NULL;
PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui = NULL;
PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv = NULL;
PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui = NULL;
PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv = NULL;
PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui = NULL;
PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv = NULL;
PFNGLNORMALP3UIPROC glNormalP3ui = NULL;
PFNGLNORMALP3UIVPROC glNormalP3uiv = NULL;
PFNGLCOLORP3UIPROC glColorP3ui = NULL;
PFNGLCOLORP3UIVPROC glColorP3uiv = NULL;
PFNGLCOLORP4UIPROC glColorP4ui = NULL;
PFNGLCOLORP4UIVPROC glColorP4uiv = NULL;
PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui = NULL;
PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv = NULL;
PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui = NULL;
PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv = NULL;
PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui = NULL;
PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv = NULL;
PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui = NULL;
PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv = NULL;
PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui = NULL;
PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 4.0
//////////////////////////////////////////////////////////////////////
PFNGLMINSAMPLESHADINGPROC glMinSampleShading = NULL;
PFNGLBLENDEQUATIONIPROC glBlendEquationi = NULL;
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei = NULL;
PFNGLBLENDFUNCIPROC glBlendFunci = NULL;
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_draw_indirect (OpenGL 4.0)
//////////////////////////////////////////////////////////////////////
PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect = NULL;
PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_gpu_shader_fp64 (OpenGL 4.0)
//////////////////////////////////////////////////////////////////////
PFNGLUNIFORM1DPROC glUniform1d = NULL;
PFNGLUNIFORM2DPROC glUniform2d = NULL;
PFNGLUNIFORM3DPROC glUniform3d = NULL;
PFNGLUNIFORM4DPROC glUniform4d = NULL;
PFNGLUNIFORM1DVPROC glUniform1dv = NULL;
PFNGLUNIFORM2DVPROC glUniform2dv = NULL;
PFNGLUNIFORM3DVPROC glUniform3dv = NULL;
PFNGLUNIFORM4DVPROC glUniform4dv = NULL;
PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv = NULL;
PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv = NULL;
PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv = NULL;
PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv = NULL;
PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv = NULL;
PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv = NULL;
PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv = NULL;
PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv = NULL;
PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv = NULL;
PFNGLGETUNIFORMDVPROC glGetUniformdv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_shader_subroutine (OpenGL 4.0)
//////////////////////////////////////////////////////////////////////
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation = NULL;
PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex = NULL;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv = NULL;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName = NULL;
PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName = NULL;
PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv = NULL;
PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv = NULL;
PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_tessellation_shader (OpenGL 4.0)
//////////////////////////////////////////////////////////////////////
PFNGLPATCHPARAMETERIPROC glPatchParameteri = NULL;
PFNGLPATCHPARAMETERFVPROC glPatchParameterfv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_transform_feedback2 (OpenGL 4.0)
//////////////////////////////////////////////////////////////////////
PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback = NULL;
PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks = NULL;
PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks = NULL;
PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback = NULL;
PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback = NULL;
PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback = NULL;
PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_transform_feedback3 (OpenGL 4.0)
//////////////////////////////////////////////////////////////////////
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream = NULL;
PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed = NULL;
PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed = NULL;
PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_ES2_compatibility (OpenGL 4.1)
//////////////////////////////////////////////////////////////////////
PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler = NULL;
PFNGLSHADERBINARYPROC glShaderBinary = NULL;
PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat = NULL;
PFNGLDEPTHRANGEFPROC glDepthRangef = NULL;
PFNGLCLEARDEPTHFPROC glClearDepthf = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_get_program_binary (OpenGL 4.1)
//////////////////////////////////////////////////////////////////////
PFNGLGETPROGRAMBINARYPROC glGetProgramBinary = NULL;
PFNGLPROGRAMBINARYPROC glProgramBinary = NULL;
PFNGLPROGRAMPARAMETERIPROC glProgramParameteri = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_separate_shader_objects (OpenGL 4.1)
//////////////////////////////////////////////////////////////////////
PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages = NULL;
PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram = NULL;
PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv = NULL;
PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline = NULL;
PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines = NULL;
PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines = NULL;
PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline = NULL;
PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv = NULL;
PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i = NULL;
PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv = NULL;
PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f = NULL;
PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv = NULL;
PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d = NULL;
PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv = NULL;
PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui = NULL;
PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv = NULL;
PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i = NULL;
PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv = NULL;
PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f = NULL;
PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv = NULL;
PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d = NULL;
PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv = NULL;
PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui = NULL;
PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv = NULL;
PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i = NULL;
PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv = NULL;
PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f = NULL;
PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv = NULL;
PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d = NULL;
PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv = NULL;
PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui = NULL;
PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv = NULL;
PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i = NULL;
PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv = NULL;
PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f = NULL;
PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv = NULL;
PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d = NULL;
PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv = NULL;
PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui = NULL;
PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv = NULL;
PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline = NULL;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_vertex_attrib_64bit (OpenGL 4.1)
//////////////////////////////////////////////////////////////////////
PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d = NULL;
PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d = NULL;
PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d = NULL;
PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d = NULL;
PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv = NULL;
PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv = NULL;
PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv = NULL;
PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv = NULL;
PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer = NULL;
PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_viewport_array (OpenGL 4.1)
//////////////////////////////////////////////////////////////////////
PFNGLVIEWPORTARRAYVPROC glViewportArrayv = NULL;
PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf = NULL;
PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv = NULL;
PFNGLSCISSORARRAYVPROC glScissorArrayv = NULL;
PFNGLSCISSORINDEXEDPROC glScissorIndexed = NULL;
PFNGLSCISSORINDEXEDVPROC glScissorIndexedv = NULL;
PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv = NULL;
PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed = NULL;
PFNGLGETFLOATI_VPROC glGetFloati_v = NULL;
PFNGLGETDOUBLEI_VPROC glGetDoublei_v = NULL;

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 3.0
//////////////////////////////////////////////////////////////////////
bool OpenGL30()
{
    if( OpenGLVersion() < 30 )
        return false;

    // pobranie wskaünikÛw funkcji pochodzπcych z OpenGL 1.2
    glBlendColor = reinterpret_cast < PFNGLBLENDCOLORPROC > ( wglGetProcAddress ( "glBlendColor" ) );
    glBlendEquation = reinterpret_cast < PFNGLBLENDEQUATIONPROC > ( wglGetProcAddress ( "glBlendEquation" ) );
    glDrawRangeElements = reinterpret_cast < PFNGLDRAWRANGEELEMENTSPROC > ( wglGetProcAddress ( "glDrawRangeElements" ) );
    glTexImage3D = reinterpret_cast < PFNGLTEXIMAGE3DPROC > ( wglGetProcAddress ( "glTexImage3D" ) );
    glTexSubImage3D = reinterpret_cast < PFNGLTEXSUBIMAGE3DPROC > ( wglGetProcAddress ( "glTexSubImage3D" ) );
    glCopyTexSubImage3D = reinterpret_cast < PFNGLCOPYTEXSUBIMAGE3DPROC > ( wglGetProcAddress ( "glCopyTexSubImage3D" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 1.3
    glActiveTexture = reinterpret_cast < PFNGLACTIVETEXTUREPROC > ( wglGetProcAddress ( "glActiveTexture" ) );
    glSampleCoverage = reinterpret_cast < PFNGLSAMPLECOVERAGEPROC > ( wglGetProcAddress ( "glSampleCoverage" ) );
    glCompressedTexImage3D = reinterpret_cast < PFNGLCOMPRESSEDTEXIMAGE3DPROC > ( wglGetProcAddress ( "glCompressedTexImage3D" ) );
    glCompressedTexImage2D = reinterpret_cast < PFNGLCOMPRESSEDTEXIMAGE2DPROC > ( wglGetProcAddress ( "glCompressedTexImage2D" ) );
    glCompressedTexImage1D = reinterpret_cast < PFNGLCOMPRESSEDTEXIMAGE1DPROC > ( wglGetProcAddress ( "glCompressedTexImage1D" ) );
    glCompressedTexSubImage3D = reinterpret_cast < PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC > ( wglGetProcAddress ( "glCompressedTexSubImage3D" ) );
    glCompressedTexSubImage2D = reinterpret_cast < PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC > ( wglGetProcAddress ( "glCompressedTexSubImage2D" ) );
    glCompressedTexSubImage1D = reinterpret_cast < PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC > ( wglGetProcAddress ( "glCompressedTexSubImage1D" ) );
    glGetCompressedTexImage = reinterpret_cast < PFNGLGETCOMPRESSEDTEXIMAGEPROC > ( wglGetProcAddress ( "glGetCompressedTexImage" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 1.4
    glBlendFuncSeparate = reinterpret_cast < PFNGLBLENDFUNCSEPARATEPROC > ( wglGetProcAddress ( "glBlendFuncSeparate" ) );
    glMultiDrawArrays = reinterpret_cast < PFNGLMULTIDRAWARRAYSPROC > ( wglGetProcAddress ( "glMultiDrawArrays" ) );
    glMultiDrawElements = reinterpret_cast < PFNGLMULTIDRAWELEMENTSPROC > ( wglGetProcAddress ( "glMultiDrawElements" ) );
    glPointParameterf = reinterpret_cast < PFNGLPOINTPARAMETERFPROC > ( wglGetProcAddress ( "glPointParameterf" ) );
    glPointParameterfv = reinterpret_cast < PFNGLPOINTPARAMETERFVPROC > ( wglGetProcAddress ( "glPointParameterfv" ) );
    glPointParameteri = reinterpret_cast < PFNGLPOINTPARAMETERIPROC > ( wglGetProcAddress ( "glPointParameteri" ) );
    glPointParameteriv = reinterpret_cast < PFNGLPOINTPARAMETERIVPROC > ( wglGetProcAddress ( "glPointParameteriv" ) );

    // pobranie wskaünikÛ wpochodzπcych z OpenGL 1.5
    glGenQueries = reinterpret_cast < PFNGLGENQUERIESPROC > ( wglGetProcAddress ( "glGenQueries" ) );
    glDeleteQueries = reinterpret_cast < PFNGLDELETEQUERIESPROC > ( wglGetProcAddress ( "glDeleteQueries" ) );
    glIsQuery = reinterpret_cast < PFNGLISQUERYPROC > ( wglGetProcAddress ( "glIsQuery" ) );
    glBeginQuery = reinterpret_cast < PFNGLBEGINQUERYPROC > ( wglGetProcAddress ( "glBeginQuery" ) );
    glEndQuery = reinterpret_cast < PFNGLENDQUERYPROC > ( wglGetProcAddress ( "glEndQuery" ) );
    glGetQueryiv = reinterpret_cast < PFNGLGETQUERYIVPROC > ( wglGetProcAddress ( "glGetQueryiv" ) );
    glGetQueryObjectiv = reinterpret_cast < PFNGLGETQUERYOBJECTIVPROC > ( wglGetProcAddress ( "glGetQueryObjectiv" ) );
    glGetQueryObjectuiv = reinterpret_cast < PFNGLGETQUERYOBJECTUIVPROC > ( wglGetProcAddress ( "glGetQueryObjectuiv" ) );
    glBindBuffer = reinterpret_cast < PFNGLBINDBUFFERPROC > ( wglGetProcAddress ( "glBindBuffer" ) );
    glDeleteBuffers = reinterpret_cast < PFNGLDELETEBUFFERSPROC > ( wglGetProcAddress ( "glDeleteBuffers" ) );
    glGenBuffers = reinterpret_cast < PFNGLGENBUFFERSPROC > ( wglGetProcAddress ( "glGenBuffers" ) );
    glIsBuffer = reinterpret_cast < PFNGLISBUFFERPROC > ( wglGetProcAddress ( "glIsBuffer" ) );
    glBufferData = reinterpret_cast < PFNGLBUFFERDATAPROC > ( wglGetProcAddress ( "glBufferData" ) );
    glBufferSubData = reinterpret_cast < PFNGLBUFFERSUBDATAPROC > ( wglGetProcAddress ( "glBufferSubData" ) );
    glGetBufferSubData = reinterpret_cast < PFNGLGETBUFFERSUBDATAPROC > ( wglGetProcAddress ( "glGetBufferSubData" ) );
    glMapBuffer = reinterpret_cast < PFNGLMAPBUFFERPROC > ( wglGetProcAddress ( "glMapBuffer" ) );
    glUnmapBuffer = reinterpret_cast < PFNGLUNMAPBUFFERPROC > ( wglGetProcAddress ( "glUnmapBuffer" ) );
    glGetBufferParameteriv = reinterpret_cast < PFNGLGETBUFFERPARAMETERIVPROC > ( wglGetProcAddress ( "glGetBufferParameteriv" ) );
    glGetBufferPointerv = reinterpret_cast < PFNGLGETBUFFERPOINTERVPROC > ( wglGetProcAddress ( "glGetBufferPointerv" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 2.0
    glBlendEquationSeparate = reinterpret_cast < PFNGLBLENDEQUATIONSEPARATEPROC > ( wglGetProcAddress ( "glBlendEquationSeparate" ) );
    glDrawBuffers = reinterpret_cast < PFNGLDRAWBUFFERSPROC > ( wglGetProcAddress ( "glDrawBuffers" ) );
    glStencilOpSeparate = reinterpret_cast < PFNGLSTENCILOPSEPARATEPROC > ( wglGetProcAddress ( "glStencilOpSeparate" ) );
    glStencilFuncSeparate = reinterpret_cast < PFNGLSTENCILFUNCSEPARATEPROC > ( wglGetProcAddress ( "glStencilFuncSeparate" ) );
    glStencilMaskSeparate = reinterpret_cast < PFNGLSTENCILMASKSEPARATEPROC > ( wglGetProcAddress ( "glStencilMaskSeparate" ) );
    glAttachShader = reinterpret_cast < PFNGLATTACHSHADERPROC > ( wglGetProcAddress ( "glAttachShader" ) );
    glBindAttribLocation = reinterpret_cast < PFNGLBINDATTRIBLOCATIONPROC > ( wglGetProcAddress ( "glBindAttribLocation" ) );
    glCompileShader = reinterpret_cast < PFNGLCOMPILESHADERPROC > ( wglGetProcAddress ( "glCompileShader" ) );
    glCreateProgram = reinterpret_cast < PFNGLCREATEPROGRAMPROC > ( wglGetProcAddress ( "glCreateProgram" ) );
    glCreateShader = reinterpret_cast < PFNGLCREATESHADERPROC > ( wglGetProcAddress ( "glCreateShader" ) );
    glDeleteProgram = reinterpret_cast < PFNGLDELETEPROGRAMPROC > ( wglGetProcAddress ( "glDeleteProgram" ) );
    glDeleteShader = reinterpret_cast < PFNGLDELETESHADERPROC > ( wglGetProcAddress ( "glDeleteShader" ) );
    glDetachShader = reinterpret_cast < PFNGLDETACHSHADERPROC > ( wglGetProcAddress ( "glDetachShader" ) );
    glDisableVertexAttribArray = reinterpret_cast < PFNGLDISABLEVERTEXATTRIBARRAYPROC > ( wglGetProcAddress ( "glDisableVertexAttribArray" ) );
    glEnableVertexAttribArray = reinterpret_cast < PFNGLENABLEVERTEXATTRIBARRAYPROC > ( wglGetProcAddress ( "glEnableVertexAttribArray" ) );
    glGetActiveAttrib = reinterpret_cast < PFNGLGETACTIVEATTRIBPROC > ( wglGetProcAddress ( "glGetActiveAttrib" ) );
    glGetActiveUniform = reinterpret_cast < PFNGLGETACTIVEUNIFORMPROC > ( wglGetProcAddress ( "glGetActiveUniform" ) );
    glGetAttachedShaders = reinterpret_cast < PFNGLGETATTACHEDSHADERSPROC > ( wglGetProcAddress ( "glGetAttachedShaders" ) );
    glGetAttribLocation = reinterpret_cast < PFNGLGETATTRIBLOCATIONPROC > ( wglGetProcAddress ( "glGetAttribLocation" ) );
    glGetProgramiv = reinterpret_cast < PFNGLGETPROGRAMIVPROC > ( wglGetProcAddress ( "glGetProgramiv" ) );
    glGetProgramInfoLog = reinterpret_cast < PFNGLGETPROGRAMINFOLOGPROC > ( wglGetProcAddress ( "glGetProgramInfoLog" ) );
    glGetShaderiv = reinterpret_cast < PFNGLGETSHADERIVPROC > ( wglGetProcAddress ( "glGetShaderiv" ) );
    glGetShaderInfoLog = reinterpret_cast < PFNGLGETSHADERINFOLOGPROC > ( wglGetProcAddress ( "glGetShaderInfoLog" ) );
    glGetShaderSource = reinterpret_cast < PFNGLGETSHADERSOURCEPROC > ( wglGetProcAddress ( "glGetShaderSource" ) );
    glGetUniformLocation = reinterpret_cast < PFNGLGETUNIFORMLOCATIONPROC > ( wglGetProcAddress ( "glGetUniformLocation" ) );
    glGetUniformfv = reinterpret_cast < PFNGLGETUNIFORMFVPROC > ( wglGetProcAddress ( "glGetUniformfv" ) );
    glGetUniformiv = reinterpret_cast < PFNGLGETUNIFORMIVPROC > ( wglGetProcAddress ( "glGetUniformiv" ) );
    glGetVertexAttribdv = reinterpret_cast < PFNGLGETVERTEXATTRIBDVPROC > ( wglGetProcAddress ( "glGetVertexAttribdv" ) );
    glGetVertexAttribfv = reinterpret_cast < PFNGLGETVERTEXATTRIBFVPROC > ( wglGetProcAddress ( "glGetVertexAttribfv" ) );
    glGetVertexAttribiv = reinterpret_cast < PFNGLGETVERTEXATTRIBIVPROC > ( wglGetProcAddress ( "glGetVertexAttribiv" ) );
    glGetVertexAttribPointerv = reinterpret_cast < PFNGLGETVERTEXATTRIBPOINTERVPROC > ( wglGetProcAddress ( "glGetVertexAttribPointerv" ) );
    glIsProgram = reinterpret_cast < PFNGLISPROGRAMPROC > ( wglGetProcAddress ( "glIsProgram" ) );
    glIsShader = reinterpret_cast < PFNGLISSHADERPROC > ( wglGetProcAddress ( "glIsShader" ) );
    glLinkProgram = reinterpret_cast < PFNGLLINKPROGRAMPROC > ( wglGetProcAddress ( "glLinkProgram" ) );
    glShaderSource = reinterpret_cast < PFNGLSHADERSOURCEPROC > ( wglGetProcAddress ( "glShaderSource" ) );
    glUseProgram = reinterpret_cast < PFNGLUSEPROGRAMPROC > ( wglGetProcAddress ( "glUseProgram" ) );
    glUniform1f = reinterpret_cast < PFNGLUNIFORM1FPROC > ( wglGetProcAddress ( "glUniform1f" ) );
    glUniform2f = reinterpret_cast < PFNGLUNIFORM2FPROC > ( wglGetProcAddress ( "glUniform2f" ) );
    glUniform3f = reinterpret_cast < PFNGLUNIFORM3FPROC > ( wglGetProcAddress ( "glUniform3f" ) );
    glUniform4f = reinterpret_cast < PFNGLUNIFORM4FPROC > ( wglGetProcAddress ( "glUniform4f" ) );
    glUniform1i = reinterpret_cast < PFNGLUNIFORM1IPROC > ( wglGetProcAddress ( "glUniform1i" ) );
    glUniform2i = reinterpret_cast < PFNGLUNIFORM2IPROC > ( wglGetProcAddress ( "glUniform2i" ) );
    glUniform3i = reinterpret_cast < PFNGLUNIFORM3IPROC > ( wglGetProcAddress ( "glUniform3i" ) );
    glUniform4i = reinterpret_cast < PFNGLUNIFORM4IPROC > ( wglGetProcAddress ( "glUniform4i" ) );
    glUniform1fv = reinterpret_cast < PFNGLUNIFORM1FVPROC > ( wglGetProcAddress ( "glUniform1fv" ) );
    glUniform2fv = reinterpret_cast < PFNGLUNIFORM2FVPROC > ( wglGetProcAddress ( "glUniform2fv" ) );
    glUniform3fv = reinterpret_cast < PFNGLUNIFORM3FVPROC > ( wglGetProcAddress ( "glUniform3fv" ) );
    glUniform4fv = reinterpret_cast < PFNGLUNIFORM4FVPROC > ( wglGetProcAddress ( "glUniform4fv" ) );
    glUniform1iv = reinterpret_cast < PFNGLUNIFORM1IVPROC > ( wglGetProcAddress ( "glUniform1iv" ) );
    glUniform2iv = reinterpret_cast < PFNGLUNIFORM2IVPROC > ( wglGetProcAddress ( "glUniform2iv" ) );
    glUniform3iv = reinterpret_cast < PFNGLUNIFORM3IVPROC > ( wglGetProcAddress ( "glUniform3iv" ) );
    glUniform4iv = reinterpret_cast < PFNGLUNIFORM4IVPROC > ( wglGetProcAddress ( "glUniform4iv" ) );
    glUniformMatrix2fv = reinterpret_cast < PFNGLUNIFORMMATRIX2FVPROC > ( wglGetProcAddress ( "glUniformMatrix2fv" ) );
    glUniformMatrix3fv = reinterpret_cast < PFNGLUNIFORMMATRIX3FVPROC > ( wglGetProcAddress ( "glUniformMatrix3fv" ) );
    glUniformMatrix4fv = reinterpret_cast < PFNGLUNIFORMMATRIX4FVPROC > ( wglGetProcAddress ( "glUniformMatrix4fv" ) );
    glValidateProgram = reinterpret_cast < PFNGLVALIDATEPROGRAMPROC > ( wglGetProcAddress ( "glValidateProgram" ) );
    glVertexAttrib1d = reinterpret_cast < PFNGLVERTEXATTRIB1DPROC > ( wglGetProcAddress ( "glVertexAttrib1d" ) );
    glVertexAttrib1dv = reinterpret_cast < PFNGLVERTEXATTRIB1DVPROC > ( wglGetProcAddress ( "glVertexAttrib1dv" ) );
    glVertexAttrib1f = reinterpret_cast < PFNGLVERTEXATTRIB1FPROC > ( wglGetProcAddress ( "glVertexAttrib1f" ) );
    glVertexAttrib1fv = reinterpret_cast < PFNGLVERTEXATTRIB1FVPROC > ( wglGetProcAddress ( "glVertexAttrib1fv" ) );
    glVertexAttrib1s = reinterpret_cast < PFNGLVERTEXATTRIB1SPROC > ( wglGetProcAddress ( "glVertexAttrib1s" ) );
    glVertexAttrib1sv = reinterpret_cast < PFNGLVERTEXATTRIB1SVPROC > ( wglGetProcAddress ( "glVertexAttrib1sv" ) );
    glVertexAttrib2d = reinterpret_cast < PFNGLVERTEXATTRIB2DPROC > ( wglGetProcAddress ( "glVertexAttrib2d" ) );
    glVertexAttrib2dv = reinterpret_cast < PFNGLVERTEXATTRIB2DVPROC > ( wglGetProcAddress ( "glVertexAttrib2dv" ) );
    glVertexAttrib2f = reinterpret_cast < PFNGLVERTEXATTRIB2FPROC > ( wglGetProcAddress ( "glVertexAttrib2f" ) );
    glVertexAttrib2fv = reinterpret_cast < PFNGLVERTEXATTRIB2FVPROC > ( wglGetProcAddress ( "glVertexAttrib2fv" ) );
    glVertexAttrib2s = reinterpret_cast < PFNGLVERTEXATTRIB2SPROC > ( wglGetProcAddress ( "glVertexAttrib2s" ) );
    glVertexAttrib2sv = reinterpret_cast < PFNGLVERTEXATTRIB2SVPROC > ( wglGetProcAddress ( "glVertexAttrib2sv" ) );
    glVertexAttrib3d = reinterpret_cast < PFNGLVERTEXATTRIB3DPROC > ( wglGetProcAddress ( "glVertexAttrib3d" ) );
    glVertexAttrib3dv = reinterpret_cast < PFNGLVERTEXATTRIB3DVPROC > ( wglGetProcAddress ( "glVertexAttrib3dv" ) );
    glVertexAttrib3f = reinterpret_cast < PFNGLVERTEXATTRIB3FPROC > ( wglGetProcAddress ( "glVertexAttrib3f" ) );
    glVertexAttrib3fv = reinterpret_cast < PFNGLVERTEXATTRIB3FVPROC > ( wglGetProcAddress ( "glVertexAttrib3fv" ) );
    glVertexAttrib3s = reinterpret_cast < PFNGLVERTEXATTRIB3SPROC > ( wglGetProcAddress ( "glVertexAttrib3s" ) );
    glVertexAttrib3sv = reinterpret_cast < PFNGLVERTEXATTRIB3SVPROC > ( wglGetProcAddress ( "glVertexAttrib3sv" ) );
    glVertexAttrib4Nbv = reinterpret_cast < PFNGLVERTEXATTRIB4NBVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nbv" ) );
    glVertexAttrib4Niv = reinterpret_cast < PFNGLVERTEXATTRIB4NIVPROC > ( wglGetProcAddress ( "glVertexAttrib4Niv" ) );
    glVertexAttrib4Nsv = reinterpret_cast < PFNGLVERTEXATTRIB4NSVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nsv" ) );
    glVertexAttrib4Nub = reinterpret_cast < PFNGLVERTEXATTRIB4NUBPROC > ( wglGetProcAddress ( "glVertexAttrib4Nub" ) );
    glVertexAttrib4Nubv = reinterpret_cast < PFNGLVERTEXATTRIB4NUBVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nubv" ) );
    glVertexAttrib4Nuiv = reinterpret_cast < PFNGLVERTEXATTRIB4NUIVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nuiv" ) );
    glVertexAttrib4Nusv = reinterpret_cast < PFNGLVERTEXATTRIB4NUSVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nusv" ) );
    glVertexAttrib4bv = reinterpret_cast < PFNGLVERTEXATTRIB4BVPROC > ( wglGetProcAddress ( "glVertexAttrib4bv" ) );
    glVertexAttrib4d = reinterpret_cast < PFNGLVERTEXATTRIB4DPROC > ( wglGetProcAddress ( "glVertexAttrib4d" ) );
    glVertexAttrib4dv = reinterpret_cast < PFNGLVERTEXATTRIB4DVPROC > ( wglGetProcAddress ( "glVertexAttrib4dv" ) );
    glVertexAttrib4f = reinterpret_cast < PFNGLVERTEXATTRIB4FPROC > ( wglGetProcAddress ( "glVertexAttrib4f" ) );
    glVertexAttrib4fv = reinterpret_cast < PFNGLVERTEXATTRIB4FVPROC > ( wglGetProcAddress ( "glVertexAttrib4fv" ) );
    glVertexAttrib4iv = reinterpret_cast < PFNGLVERTEXATTRIB4IVPROC > ( wglGetProcAddress ( "glVertexAttrib4iv" ) );
    glVertexAttrib4s = reinterpret_cast < PFNGLVERTEXATTRIB4SPROC > ( wglGetProcAddress ( "glVertexAttrib4s" ) );
    glVertexAttrib4sv = reinterpret_cast < PFNGLVERTEXATTRIB4SVPROC > ( wglGetProcAddress ( "glVertexAttrib4sv" ) );
    glVertexAttrib4ubv = reinterpret_cast < PFNGLVERTEXATTRIB4UBVPROC > ( wglGetProcAddress ( "glVertexAttrib4ubv" ) );
    glVertexAttrib4uiv = reinterpret_cast < PFNGLVERTEXATTRIB4UIVPROC > ( wglGetProcAddress ( "glVertexAttrib4uiv" ) );
    glVertexAttrib4usv = reinterpret_cast < PFNGLVERTEXATTRIB4USVPROC > ( wglGetProcAddress ( "glVertexAttrib4usv" ) );
    glVertexAttribPointer = reinterpret_cast < PFNGLVERTEXATTRIBPOINTERPROC > ( wglGetProcAddress ( "glVertexAttribPointer" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 2.1
    glUniformMatrix2x3fv = reinterpret_cast < PFNGLUNIFORMMATRIX2X3FVPROC > ( wglGetProcAddress ( "glUniformMatrix2x3fv" ) );
    glUniformMatrix3x2fv = reinterpret_cast < PFNGLUNIFORMMATRIX3X2FVPROC > ( wglGetProcAddress ( "glUniformMatrix3x2fv" ) );
    glUniformMatrix2x4fv = reinterpret_cast < PFNGLUNIFORMMATRIX2X4FVPROC > ( wglGetProcAddress ( "glUniformMatrix2x4fv" ) );
    glUniformMatrix4x2fv = reinterpret_cast < PFNGLUNIFORMMATRIX4X2FVPROC > ( wglGetProcAddress ( "glUniformMatrix4x2fv" ) );
    glUniformMatrix3x4fv = reinterpret_cast < PFNGLUNIFORMMATRIX3X4FVPROC > ( wglGetProcAddress ( "glUniformMatrix3x4fv" ) );
    glUniformMatrix4x3fv = reinterpret_cast < PFNGLUNIFORMMATRIX4X3FVPROC > ( wglGetProcAddress ( "glUniformMatrix4x3fv" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 3.0
    glColorMaski = reinterpret_cast < PFNGLCOLORMASKIPROC > ( wglGetProcAddress( "glColorMaski" ) );
    glGetBooleani_v = reinterpret_cast < PFNGLGETBOOLEANI_VPROC > ( wglGetProcAddress( "glGetBooleani_v" ) );
    glGetIntegeri_v = reinterpret_cast < PFNGLGETINTEGERI_VPROC > ( wglGetProcAddress( "glGetIntegeri_v" ) );
    glEnablei = reinterpret_cast < PFNGLENABLEIPROC > ( wglGetProcAddress( "glEnablei" ) );
    glDisablei = reinterpret_cast < PFNGLDISABLEIPROC > ( wglGetProcAddress( "glDisablei" ) );
    glIsEnabledi = reinterpret_cast < PFNGLISENABLEDIPROC > ( wglGetProcAddress( "glIsEnabledi" ) );
    glBeginTransformFeedback = reinterpret_cast < PFNGLBEGINTRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glBeginTransformFeedback" ) );
    glEndTransformFeedback = reinterpret_cast < PFNGLENDTRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glEndTransformFeedback" ) );
    glBindBufferRange = reinterpret_cast < PFNGLBINDBUFFERRANGEPROC > ( wglGetProcAddress( "glBindBufferRange" ) );
    glBindBufferBase = reinterpret_cast < PFNGLBINDBUFFERBASEPROC > ( wglGetProcAddress( "glBindBufferBase" ) );
    glTransformFeedbackVaryings = reinterpret_cast < PFNGLTRANSFORMFEEDBACKVARYINGSPROC > ( wglGetProcAddress( "glTransformFeedbackVaryings" ) );
    glGetTransformFeedbackVarying = reinterpret_cast < PFNGLGETTRANSFORMFEEDBACKVARYINGPROC > ( wglGetProcAddress( "glGetTransformFeedbackVarying" ) );
    glClampColor = reinterpret_cast < PFNGLCLAMPCOLORPROC > ( wglGetProcAddress( "glClampColor" ) );
    glBeginConditionalRender = reinterpret_cast < PFNGLBEGINCONDITIONALRENDERPROC > ( wglGetProcAddress( "glBeginConditionalRender" ) );
    glEndConditionalRender = reinterpret_cast < PFNGLENDCONDITIONALRENDERPROC > ( wglGetProcAddress( "glEndConditionalRender" ) );
    glVertexAttribIPointer = reinterpret_cast < PFNGLVERTEXATTRIBIPOINTERPROC > ( wglGetProcAddress( "glVertexAttribIPointer" ) );
    glGetVertexAttribIiv = reinterpret_cast < PFNGLGETVERTEXATTRIBIIVPROC > ( wglGetProcAddress( "glGetVertexAttribIiv" ) );
    glGetVertexAttribIuiv = reinterpret_cast < PFNGLGETVERTEXATTRIBIUIVPROC > ( wglGetProcAddress( "glGetVertexAttribIuiv" ) );
    glGetUniformuiv = reinterpret_cast < PFNGLGETUNIFORMUIVPROC > ( wglGetProcAddress( "glGetUniformuiv" ) );
    glBindFragDataLocation = reinterpret_cast < PFNGLBINDFRAGDATALOCATIONPROC > ( wglGetProcAddress( "glBindFragDataLocation" ) );
    glGetFragDataLocation = reinterpret_cast < PFNGLGETFRAGDATALOCATIONPROC > ( wglGetProcAddress( "glGetFragDataLocation" ) );
    glUniform1ui = reinterpret_cast < PFNGLUNIFORM1UIPROC > ( wglGetProcAddress( "glUniform1ui" ) );
    glUniform2ui = reinterpret_cast < PFNGLUNIFORM2UIPROC > ( wglGetProcAddress( "glUniform2ui" ) );
    glUniform3ui = reinterpret_cast < PFNGLUNIFORM3UIPROC > ( wglGetProcAddress( "glUniform3ui" ) );
    glUniform4ui = reinterpret_cast < PFNGLUNIFORM4UIPROC > ( wglGetProcAddress( "glUniform4ui" ) );
    glUniform1uiv = reinterpret_cast < PFNGLUNIFORM1UIVPROC > ( wglGetProcAddress( "glUniform1uiv" ) );
    glUniform2uiv = reinterpret_cast < PFNGLUNIFORM2UIVPROC > ( wglGetProcAddress( "glUniform2uiv" ) );
    glUniform3uiv = reinterpret_cast < PFNGLUNIFORM3UIVPROC > ( wglGetProcAddress( "glUniform3uiv" ) );
    glUniform4uiv = reinterpret_cast < PFNGLUNIFORM4UIVPROC > ( wglGetProcAddress( "glUniform4uiv" ) );
    glTexParameterIiv = reinterpret_cast < PFNGLTEXPARAMETERIIVPROC > ( wglGetProcAddress( "glTexParameterIiv" ) );
    glTexParameterIuiv = reinterpret_cast < PFNGLTEXPARAMETERIUIVPROC > ( wglGetProcAddress( "glTexParameterIuiv" ) );
    glGetTexParameterIiv = reinterpret_cast < PFNGLGETTEXPARAMETERIIVPROC > ( wglGetProcAddress( "glGetTexParameterIiv" ) );
    glGetTexParameterIuiv = reinterpret_cast < PFNGLGETTEXPARAMETERIUIVPROC > ( wglGetProcAddress( "glGetTexParameterIuiv" ) );
    glClearBufferiv = reinterpret_cast < PFNGLCLEARBUFFERIVPROC > ( wglGetProcAddress( "glClearBufferiv" ) );
    glClearBufferuiv = reinterpret_cast < PFNGLCLEARBUFFERUIVPROC > ( wglGetProcAddress( "glClearBufferuiv" ) );
    glClearBufferfv = reinterpret_cast < PFNGLCLEARBUFFERFVPROC > ( wglGetProcAddress( "glClearBufferfv" ) );
    glClearBufferfi = reinterpret_cast < PFNGLCLEARBUFFERFIPROC > ( wglGetProcAddress( "glClearBufferfi" ) );
    glGetStringi = reinterpret_cast < PFNGLGETSTRINGIPROC > ( wglGetProcAddress( "glGetStringi" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_framebuffer_object
    glIsRenderbuffer = reinterpret_cast < PFNGLISRENDERBUFFERPROC > ( wglGetProcAddress( "glIsRenderbuffer" ) );
    glBindRenderbuffer = reinterpret_cast < PFNGLBINDRENDERBUFFERPROC > ( wglGetProcAddress( "glBindRenderbuffer" ) );
    glDeleteRenderbuffers = reinterpret_cast < PFNGLDELETERENDERBUFFERSPROC > ( wglGetProcAddress( "glDeleteRenderbuffers" ) );
    glGenRenderbuffers = reinterpret_cast < PFNGLGENRENDERBUFFERSPROC > ( wglGetProcAddress( "glGenRenderbuffers" ) );
    glRenderbufferStorage = reinterpret_cast < PFNGLRENDERBUFFERSTORAGEPROC > ( wglGetProcAddress( "glRenderbufferStorage" ) );
    glGetRenderbufferParameteriv = reinterpret_cast < PFNGLGETRENDERBUFFERPARAMETERIVPROC > ( wglGetProcAddress( "glGetRenderbufferParameteriv" ) );
    glIsFramebuffer = reinterpret_cast < PFNGLISFRAMEBUFFERPROC > ( wglGetProcAddress( "glIsFramebuffer" ) );
    glBindFramebuffer = reinterpret_cast < PFNGLBINDFRAMEBUFFERPROC > ( wglGetProcAddress( "glBindFramebuffer" ) );
    glDeleteFramebuffers = reinterpret_cast < PFNGLDELETEFRAMEBUFFERSPROC > ( wglGetProcAddress( "glDeleteFramebuffers" ) );
    glGenFramebuffers = reinterpret_cast < PFNGLGENFRAMEBUFFERSPROC > ( wglGetProcAddress( "glGenFramebuffers" ) );
    glCheckFramebufferStatus = reinterpret_cast < PFNGLCHECKFRAMEBUFFERSTATUSPROC > ( wglGetProcAddress( "glCheckFramebufferStatus" ) );
    glFramebufferTexture1D = reinterpret_cast < PFNGLFRAMEBUFFERTEXTURE1DPROC > ( wglGetProcAddress( "glFramebufferTexture1D" ) );
    glFramebufferTexture2D = reinterpret_cast < PFNGLFRAMEBUFFERTEXTURE2DPROC > ( wglGetProcAddress( "glFramebufferTexture2D" ) );
    glFramebufferTexture3D = reinterpret_cast < PFNGLFRAMEBUFFERTEXTURE3DPROC > ( wglGetProcAddress( "glFramebufferTexture3D" ) );
    glFramebufferRenderbuffer = reinterpret_cast < PFNGLFRAMEBUFFERRENDERBUFFERPROC > ( wglGetProcAddress( "glFramebufferRenderbuffer" ) );
    glGetFramebufferAttachmentParameteriv = reinterpret_cast < PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC > ( wglGetProcAddress( "glGetFramebufferAttachmentParameteriv" ) );
    glGenerateMipmap = reinterpret_cast < PFNGLGENERATEMIPMAPPROC > ( wglGetProcAddress( "glGenerateMipmap" ) );
    glBlitFramebuffer = reinterpret_cast < PFNGLBLITFRAMEBUFFERPROC > ( wglGetProcAddress( "glBlitFramebuffer" ) );
    glRenderbufferStorageMultisample = reinterpret_cast < PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC > ( wglGetProcAddress( "glRenderbufferStorageMultisample" ) );
    glFramebufferTextureLayer = reinterpret_cast < PFNGLFRAMEBUFFERTEXTURELAYERPROC > ( wglGetProcAddress( "glFramebufferTextureLayer" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_map_buffer_range
    glMapBufferRange = reinterpret_cast < PFNGLMAPBUFFERRANGEPROC > ( wglGetProcAddress( "glMapBufferRange" ) );
    glFlushMappedBufferRange = reinterpret_cast < PFNGLFLUSHMAPPEDBUFFERRANGEPROC > ( wglGetProcAddress( "glFlushMappedBufferRange" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_vertex_array_object
    glBindVertexArray = reinterpret_cast < PFNGLBINDVERTEXARRAYPROC > ( wglGetProcAddress( "glBindVertexArray" ) );
    glDeleteVertexArrays = reinterpret_cast < PFNGLDELETEVERTEXARRAYSPROC > ( wglGetProcAddress( "glDeleteVertexArrays" ) );
    glGenVertexArrays = reinterpret_cast < PFNGLGENVERTEXARRAYSPROC > ( wglGetProcAddress( "glGenVertexArrays" ) );
    glIsVertexArray = reinterpret_cast < PFNGLISVERTEXARRAYPROC > ( wglGetProcAddress( "glIsVertexArray" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 3.1
//////////////////////////////////////////////////////////////////////
bool OpenGL31()
{
    // sprawdzenie numeru wersji
    if( OpenGLVersion() < 31 )
        return false;

    // pobranie wskaünikÛw
    glDrawArraysInstanced = reinterpret_cast < PFNGLDRAWARRAYSINSTANCEDPROC > ( wglGetProcAddress( "glDrawArraysInstanced" ) );
    glDrawElementsInstanced = reinterpret_cast < PFNGLDRAWELEMENTSINSTANCEDPROC > ( wglGetProcAddress( "glDrawElementsInstanced" ) );
    glTexBuffer = reinterpret_cast < PFNGLTEXBUFFERPROC > ( wglGetProcAddress( "glTexBuffer" ) );
    glPrimitiveRestartIndex = reinterpret_cast < PFNGLPRIMITIVERESTARTINDEXPROC > ( wglGetProcAddress( "glPrimitiveRestartIndex" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_uniform_buffer_object
    glGetUniformIndices = reinterpret_cast < PFNGLGETUNIFORMINDICESPROC > ( wglGetProcAddress( "glGetUniformIndices" ) );
    glGetActiveUniformsiv = reinterpret_cast < PFNGLGETACTIVEUNIFORMSIVPROC > ( wglGetProcAddress( "glGetActiveUniformsiv" ) );
    glGetActiveUniformName = reinterpret_cast < PFNGLGETACTIVEUNIFORMNAMEPROC > ( wglGetProcAddress( "glGetActiveUniformName" ) );
    glGetUniformBlockIndex = reinterpret_cast < PFNGLGETUNIFORMBLOCKINDEXPROC > ( wglGetProcAddress( "glGetUniformBlockIndex" ) );
    glGetActiveUniformBlockiv = reinterpret_cast < PFNGLGETACTIVEUNIFORMBLOCKIVPROC > ( wglGetProcAddress( "glGetActiveUniformBlockiv" ) );
    glGetActiveUniformBlockName = reinterpret_cast < PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC > ( wglGetProcAddress( "glGetActiveUniformBlockName" ) );
    glUniformBlockBinding = reinterpret_cast < PFNGLUNIFORMBLOCKBINDINGPROC > ( wglGetProcAddress( "glUniformBlockBinding" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_copy_buffer
    glCopyBufferSubData = reinterpret_cast < PFNGLCOPYBUFFERSUBDATAPROC > ( wglGetProcAddress( "glCopyBufferSubData" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 3.2
//////////////////////////////////////////////////////////////////////
bool OpenGL32()
{
    // sprawdzenie numeru wersji
    if( OpenGLVersion() < 32 )
        return false;

    // pobranie wskaünikÛw
    glGetInteger64i_v = reinterpret_cast < PFNGLGETINTEGER64I_VPROC > ( wglGetProcAddress( "glGetInteger64i_v" ) );
    glGetBufferParameteri64v = reinterpret_cast < PFNGLGETBUFFERPARAMETERI64VPROC > ( wglGetProcAddress( "glGetBufferParameteri64v" ) );
    glFramebufferTexture = reinterpret_cast < PFNGLFRAMEBUFFERTEXTUREPROC > ( wglGetProcAddress( "glFramebufferTexture" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_draw_elements_base_vertex
    glDrawElementsBaseVertex = reinterpret_cast < PFNGLDRAWELEMENTSBASEVERTEXPROC > ( wglGetProcAddress( "glDrawElementsBaseVertex" ) );
    glDrawRangeElementsBaseVertex = reinterpret_cast < PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC > ( wglGetProcAddress( "glDrawRangeElementsBaseVertex" ) );
    glDrawElementsInstancedBaseVertex = reinterpret_cast < PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC > ( wglGetProcAddress( "glDrawElementsInstancedBaseVertex" ) );
    glMultiDrawElementsBaseVertex = reinterpret_cast < PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC > ( wglGetProcAddress( "glMultiDrawElementsBaseVertex" ) );

    // pobranie wskaünikÛw -rozszerzenie GL_ARB_provoking_vertex
    glProvokingVertex = reinterpret_cast < PFNGLPROVOKINGVERTEXPROC > ( wglGetProcAddress( "glProvokingVertex" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_sync
    glFenceSync = reinterpret_cast < PFNGLFENCESYNCPROC > ( wglGetProcAddress( "glFenceSync" ) );
    glIsSync = reinterpret_cast < PFNGLISSYNCPROC > ( wglGetProcAddress( "glIsSync" ) );
    glDeleteSync = reinterpret_cast < PFNGLDELETESYNCPROC > ( wglGetProcAddress( "glDeleteSync" ) );
    glClientWaitSync = reinterpret_cast < PFNGLCLIENTWAITSYNCPROC > ( wglGetProcAddress( "glClientWaitSync" ) );
    glWaitSync = reinterpret_cast < PFNGLWAITSYNCPROC > ( wglGetProcAddress( "glWaitSync" ) );
    glGetInteger64v = reinterpret_cast < PFNGLGETINTEGER64VPROC > ( wglGetProcAddress( "glGetInteger64v" ) );
    glGetSynciv = reinterpret_cast < PFNGLGETSYNCIVPROC > ( wglGetProcAddress( "glGetSynciv" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_texture_multisample
    glTexImage2DMultisample = reinterpret_cast < PFNGLTEXIMAGE2DMULTISAMPLEPROC > ( wglGetProcAddress( "glTexImage2DMultisample" ) );
    glTexImage3DMultisample = reinterpret_cast < PFNGLTEXIMAGE3DMULTISAMPLEPROC > ( wglGetProcAddress( "glTexImage3DMultisample" ) );
    glGetMultisamplefv = reinterpret_cast < PFNGLGETMULTISAMPLEFVPROC > ( wglGetProcAddress( "glGetMultisamplefv" ) );
    glSampleMaski = reinterpret_cast < PFNGLSAMPLEMASKIPROC > ( wglGetProcAddress( "glSampleMaski" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 3.3
//////////////////////////////////////////////////////////////////////
bool OpenGL33()
{
    // sprawdzenie numeru wersji
    if( OpenGLVersion() < 33 )
        return false;

    // pobranie wskaünikÛw
    glVertexAttribDivisor = reinterpret_cast < PFNGLVERTEXATTRIBDIVISORPROC > ( wglGetProcAddress( "glVertexAttribDivisor" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_blend_func_extended
    glBindFragDataLocationIndexed = reinterpret_cast < PFNGLBINDFRAGDATALOCATIONINDEXEDPROC > ( wglGetProcAddress( "glBindFragDataLocationIndexed" ) );
    glGetFragDataIndex = reinterpret_cast < PFNGLGETFRAGDATAINDEXPROC > ( wglGetProcAddress( "glGetFragDataIndex" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_sampler_objects
    glGenSamplers = reinterpret_cast < PFNGLGENSAMPLERSPROC > ( wglGetProcAddress( "glGenSamplers" ) );
    glDeleteSamplers = reinterpret_cast < PFNGLDELETESAMPLERSPROC > ( wglGetProcAddress( "glDeleteSamplers" ) );
    glIsSampler = reinterpret_cast < PFNGLISSAMPLERPROC > ( wglGetProcAddress( "glIsSampler" ) );
    glBindSampler = reinterpret_cast < PFNGLBINDSAMPLERPROC > ( wglGetProcAddress( "glBindSampler" ) );
    glSamplerParameteri = reinterpret_cast < PFNGLSAMPLERPARAMETERIPROC > ( wglGetProcAddress( "glSamplerParameteri" ) );
    glSamplerParameteriv = reinterpret_cast < PFNGLSAMPLERPARAMETERIVPROC > ( wglGetProcAddress( "glSamplerParameteriv" ) );
    glSamplerParameterf = reinterpret_cast < PFNGLSAMPLERPARAMETERFPROC > ( wglGetProcAddress( "glSamplerParameterf" ) );
    glSamplerParameterfv = reinterpret_cast < PFNGLSAMPLERPARAMETERFVPROC > ( wglGetProcAddress( "glSamplerParameterfv" ) );
    glSamplerParameterIiv = reinterpret_cast < PFNGLSAMPLERPARAMETERIIVPROC > ( wglGetProcAddress( "glSamplerParameterIiv" ) );
    glSamplerParameterIuiv = reinterpret_cast < PFNGLSAMPLERPARAMETERIUIVPROC > ( wglGetProcAddress( "glSamplerParameterIuiv" ) );
    glGetSamplerParameteriv = reinterpret_cast < PFNGLGETSAMPLERPARAMETERIVPROC > ( wglGetProcAddress( "glGetSamplerParameteriv" ) );
    glGetSamplerParameterIiv = reinterpret_cast < PFNGLGETSAMPLERPARAMETERIIVPROC > ( wglGetProcAddress( "glGetSamplerParameterIiv" ) );
    glGetSamplerParameterfv = reinterpret_cast < PFNGLGETSAMPLERPARAMETERFVPROC > ( wglGetProcAddress( "glGetSamplerParameterfv" ) );
    glGetSamplerParameterIuiv = reinterpret_cast < PFNGLGETSAMPLERPARAMETERIUIVPROC > ( wglGetProcAddress( "glGetSamplerParameterIuiv" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_timer_query
    glQueryCounter = reinterpret_cast < PFNGLQUERYCOUNTERPROC > ( wglGetProcAddress( "glQueryCounter" ) );
    glGetQueryObjecti64v = reinterpret_cast < PFNGLGETQUERYOBJECTI64VPROC > ( wglGetProcAddress( "glGetQueryObjecti64v" ) );
    glGetQueryObjectui64v = reinterpret_cast < PFNGLGETQUERYOBJECTUI64VPROC > ( wglGetProcAddress( "glGetQueryObjectui64v" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_vertex_type_2_10_10_10_rev
    glVertexP2ui = reinterpret_cast < PFNGLVERTEXP2UIPROC > ( wglGetProcAddress( "glVertexP2ui" ) );
    glVertexP2uiv = reinterpret_cast < PFNGLVERTEXP2UIVPROC > ( wglGetProcAddress( "glVertexP2uiv" ) );
    glVertexP3ui = reinterpret_cast < PFNGLVERTEXP3UIPROC > ( wglGetProcAddress( "glVertexP3ui" ) );
    glVertexP3uiv = reinterpret_cast < PFNGLVERTEXP3UIVPROC > ( wglGetProcAddress( "glVertexP3uiv" ) );
    glVertexP4ui = reinterpret_cast < PFNGLVERTEXP4UIPROC > ( wglGetProcAddress( "glVertexP4ui" ) );
    glVertexP4uiv = reinterpret_cast < PFNGLVERTEXP4UIVPROC > ( wglGetProcAddress( "glVertexP4uiv" ) );
    glTexCoordP1ui = reinterpret_cast < PFNGLTEXCOORDP1UIPROC > ( wglGetProcAddress( "glTexCoordP1ui" ) );
    glTexCoordP1uiv = reinterpret_cast < PFNGLTEXCOORDP1UIVPROC > ( wglGetProcAddress( "glTexCoordP1uiv" ) );
    glTexCoordP2ui = reinterpret_cast < PFNGLTEXCOORDP2UIPROC > ( wglGetProcAddress( "glTexCoordP2ui" ) );
    glTexCoordP2uiv = reinterpret_cast < PFNGLTEXCOORDP2UIVPROC > ( wglGetProcAddress( "glTexCoordP2uiv" ) );
    glTexCoordP3ui = reinterpret_cast < PFNGLTEXCOORDP3UIPROC > ( wglGetProcAddress( "glTexCoordP3ui" ) );
    glTexCoordP3uiv = reinterpret_cast < PFNGLTEXCOORDP3UIVPROC > ( wglGetProcAddress( "glTexCoordP3uiv" ) );
    glTexCoordP4ui = reinterpret_cast < PFNGLTEXCOORDP4UIPROC > ( wglGetProcAddress( "glTexCoordP4ui" ) );
    glTexCoordP4uiv = reinterpret_cast < PFNGLTEXCOORDP4UIVPROC > ( wglGetProcAddress( "glTexCoordP4uiv" ) );
    glMultiTexCoordP1ui = reinterpret_cast < PFNGLMULTITEXCOORDP1UIPROC > ( wglGetProcAddress( "glMultiTexCoordP1ui" ) );
    glMultiTexCoordP1uiv = reinterpret_cast < PFNGLMULTITEXCOORDP1UIVPROC > ( wglGetProcAddress( "glMultiTexCoordP1uiv" ) );
    glMultiTexCoordP2ui = reinterpret_cast < PFNGLMULTITEXCOORDP2UIPROC > ( wglGetProcAddress( "glMultiTexCoordP2ui" ) );
    glMultiTexCoordP2uiv = reinterpret_cast < PFNGLMULTITEXCOORDP2UIVPROC > ( wglGetProcAddress( "glMultiTexCoordP2uiv" ) );
    glMultiTexCoordP3ui = reinterpret_cast < PFNGLMULTITEXCOORDP3UIPROC > ( wglGetProcAddress( "glMultiTexCoordP3ui" ) );
    glMultiTexCoordP3uiv = reinterpret_cast < PFNGLMULTITEXCOORDP3UIVPROC > ( wglGetProcAddress( "glMultiTexCoordP3uiv" ) );
    glMultiTexCoordP4ui = reinterpret_cast < PFNGLMULTITEXCOORDP4UIPROC > ( wglGetProcAddress( "glMultiTexCoordP4ui" ) );
    glMultiTexCoordP4uiv = reinterpret_cast < PFNGLMULTITEXCOORDP4UIVPROC > ( wglGetProcAddress( "glMultiTexCoordP4uiv" ) );
    glNormalP3ui = reinterpret_cast < PFNGLNORMALP3UIPROC > ( wglGetProcAddress( "glNormalP3ui" ) );
    glNormalP3uiv = reinterpret_cast < PFNGLNORMALP3UIVPROC > ( wglGetProcAddress( "glNormalP3uiv" ) );
    glColorP3ui = reinterpret_cast < PFNGLCOLORP3UIPROC > ( wglGetProcAddress( "glColorP3ui" ) );
    glColorP3uiv = reinterpret_cast < PFNGLCOLORP3UIVPROC > ( wglGetProcAddress( "glColorP3uiv" ) );
    glColorP4ui = reinterpret_cast < PFNGLCOLORP4UIPROC > ( wglGetProcAddress( "glColorP4ui" ) );
    glColorP4uiv = reinterpret_cast < PFNGLCOLORP4UIVPROC > ( wglGetProcAddress( "glColorP4uiv" ) );
    glSecondaryColorP3ui = reinterpret_cast < PFNGLSECONDARYCOLORP3UIPROC > ( wglGetProcAddress( "glSecondaryColorP3ui" ) );
    glSecondaryColorP3uiv = reinterpret_cast < PFNGLSECONDARYCOLORP3UIVPROC > ( wglGetProcAddress( "glSecondaryColorP3uiv" ) );
    glVertexAttribP1ui = reinterpret_cast < PFNGLVERTEXATTRIBP1UIPROC > ( wglGetProcAddress( "glVertexAttribP1ui" ) );
    glVertexAttribP1uiv = reinterpret_cast < PFNGLVERTEXATTRIBP1UIVPROC > ( wglGetProcAddress( "glVertexAttribP1uiv" ) );
    glVertexAttribP2ui = reinterpret_cast < PFNGLVERTEXATTRIBP2UIPROC > ( wglGetProcAddress( "glVertexAttribP2ui" ) );
    glVertexAttribP2uiv = reinterpret_cast < PFNGLVERTEXATTRIBP2UIVPROC > ( wglGetProcAddress( "glVertexAttribP2uiv" ) );
    glVertexAttribP3ui = reinterpret_cast < PFNGLVERTEXATTRIBP3UIPROC > ( wglGetProcAddress( "glVertexAttribP3ui" ) );
    glVertexAttribP3uiv = reinterpret_cast < PFNGLVERTEXATTRIBP3UIVPROC > ( wglGetProcAddress( "glVertexAttribP3uiv" ) );
    glVertexAttribP4ui = reinterpret_cast < PFNGLVERTEXATTRIBP4UIPROC > ( wglGetProcAddress( "glVertexAttribP4ui" ) );
    glVertexAttribP4uiv = reinterpret_cast < PFNGLVERTEXATTRIBP4UIVPROC > ( wglGetProcAddress( "glVertexAttribP4uiv" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 4.0
//////////////////////////////////////////////////////////////////////
bool OpenGL40()
{
    // sprawdzenie numeru wersji
    if( OpenGLVersion() < 40 )
        return false;

    // pobranie wskaünikÛw
    glMinSampleShading = reinterpret_cast < PFNGLMINSAMPLESHADINGPROC > ( wglGetProcAddress( "glMinSampleShading" ) );
    glBlendEquationi = reinterpret_cast < PFNGLBLENDEQUATIONIPROC > ( wglGetProcAddress( "glBlendEquationi" ) );
    glBlendEquationSeparatei = reinterpret_cast < PFNGLBLENDEQUATIONSEPARATEIPROC > ( wglGetProcAddress( "glBlendEquationSeparatei" ) );
    glBlendFunci = reinterpret_cast < PFNGLBLENDFUNCIPROC > ( wglGetProcAddress( "glBlendFunci" ) );
    glBlendFuncSeparatei = reinterpret_cast < PFNGLBLENDFUNCSEPARATEIPROC > ( wglGetProcAddress( "glBlendFuncSeparatei" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_draw_indirect
    glDrawArraysIndirect = reinterpret_cast < PFNGLDRAWARRAYSINDIRECTPROC > ( wglGetProcAddress( "glDrawArraysIndirect" ) );
    glDrawElementsIndirect = reinterpret_cast < PFNGLDRAWELEMENTSINDIRECTPROC > ( wglGetProcAddress( "glDrawElementsIndirect" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_gpu_shader_fp64
    glUniform1d = reinterpret_cast < PFNGLUNIFORM1DPROC > ( wglGetProcAddress( "glUniform1d" ) );
    glUniform2d = reinterpret_cast < PFNGLUNIFORM2DPROC > ( wglGetProcAddress( "glUniform2d" ) );
    glUniform3d = reinterpret_cast < PFNGLUNIFORM3DPROC > ( wglGetProcAddress( "glUniform3d" ) );
    glUniform4d = reinterpret_cast < PFNGLUNIFORM4DPROC > ( wglGetProcAddress( "glUniform4d" ) );
    glUniform1dv = reinterpret_cast < PFNGLUNIFORM1DVPROC > ( wglGetProcAddress( "glUniform1dv" ) );
    glUniform2dv = reinterpret_cast < PFNGLUNIFORM2DVPROC > ( wglGetProcAddress( "glUniform2dv" ) );
    glUniform3dv = reinterpret_cast < PFNGLUNIFORM3DVPROC > ( wglGetProcAddress( "glUniform3dv" ) );
    glUniform4dv = reinterpret_cast < PFNGLUNIFORM4DVPROC > ( wglGetProcAddress( "glUniform4dv" ) );
    glUniformMatrix2dv = reinterpret_cast < PFNGLUNIFORMMATRIX2DVPROC > ( wglGetProcAddress( "glUniformMatrix2dv" ) );
    glUniformMatrix3dv = reinterpret_cast < PFNGLUNIFORMMATRIX3DVPROC > ( wglGetProcAddress( "glUniformMatrix3dv" ) );
    glUniformMatrix4dv = reinterpret_cast < PFNGLUNIFORMMATRIX4DVPROC > ( wglGetProcAddress( "glUniformMatrix4dv" ) );
    glUniformMatrix2x3dv = reinterpret_cast < PFNGLUNIFORMMATRIX2X3DVPROC > ( wglGetProcAddress( "glUniformMatrix2x3dv" ) );
    glUniformMatrix2x4dv = reinterpret_cast < PFNGLUNIFORMMATRIX2X4DVPROC > ( wglGetProcAddress( "glUniformMatrix2x4dv" ) );
    glUniformMatrix3x2dv = reinterpret_cast < PFNGLUNIFORMMATRIX3X2DVPROC > ( wglGetProcAddress( "glUniformMatrix3x2dv" ) );
    glUniformMatrix3x4dv = reinterpret_cast < PFNGLUNIFORMMATRIX3X4DVPROC > ( wglGetProcAddress( "glUniformMatrix3x4dv" ) );
    glUniformMatrix4x2dv = reinterpret_cast < PFNGLUNIFORMMATRIX4X2DVPROC > ( wglGetProcAddress( "glUniformMatrix4x2dv" ) );
    glUniformMatrix4x3dv = reinterpret_cast < PFNGLUNIFORMMATRIX4X3DVPROC > ( wglGetProcAddress( "glUniformMatrix4x3dv" ) );
    glGetUniformdv = reinterpret_cast < PFNGLGETUNIFORMDVPROC > ( wglGetProcAddress( "glGetUniformdv" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_shader_subroutine
    glGetSubroutineUniformLocation = reinterpret_cast < PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC > ( wglGetProcAddress( "glGetSubroutineUniformLocation" ) );
    glGetSubroutineIndex = reinterpret_cast < PFNGLGETSUBROUTINEINDEXPROC > ( wglGetProcAddress( "glGetSubroutineIndex" ) );
    glGetActiveSubroutineUniformiv = reinterpret_cast < PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC > ( wglGetProcAddress( "glGetActiveSubroutineUniformiv" ) );
    glGetActiveSubroutineUniformName = reinterpret_cast < PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC > ( wglGetProcAddress( "glGetActiveSubroutineUniformName" ) );
    glGetActiveSubroutineName = reinterpret_cast < PFNGLGETACTIVESUBROUTINENAMEPROC > ( wglGetProcAddress( "glGetActiveSubroutineName" ) );
    glUniformSubroutinesuiv = reinterpret_cast < PFNGLUNIFORMSUBROUTINESUIVPROC > ( wglGetProcAddress( "glUniformSubroutinesuiv" ) );
    glGetUniformSubroutineuiv = reinterpret_cast < PFNGLGETUNIFORMSUBROUTINEUIVPROC > ( wglGetProcAddress( "glGetUniformSubroutineuiv" ) );
    glGetProgramStageiv = reinterpret_cast < PFNGLGETPROGRAMSTAGEIVPROC > ( wglGetProcAddress( "glGetProgramStageiv" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_tessellation_shader
    glPatchParameteri = reinterpret_cast < PFNGLPATCHPARAMETERIPROC > ( wglGetProcAddress( "glPatchParameteri" ) );
    glPatchParameterfv = reinterpret_cast < PFNGLPATCHPARAMETERFVPROC > ( wglGetProcAddress( "glPatchParameterfv" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_transform_feedback2
    glBindTransformFeedback = reinterpret_cast < PFNGLBINDTRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glBindTransformFeedback" ) );
    glDeleteTransformFeedbacks = reinterpret_cast < PFNGLDELETETRANSFORMFEEDBACKSPROC > ( wglGetProcAddress( "glDeleteTransformFeedbacks" ) );
    glGenTransformFeedbacks = reinterpret_cast < PFNGLGENTRANSFORMFEEDBACKSPROC > ( wglGetProcAddress( "glGenTransformFeedbacks" ) );
    glIsTransformFeedback = reinterpret_cast < PFNGLISTRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glIsTransformFeedback" ) );
    glPauseTransformFeedback = reinterpret_cast < PFNGLPAUSETRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glPauseTransformFeedback" ) );
    glResumeTransformFeedback = reinterpret_cast < PFNGLRESUMETRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glResumeTransformFeedback" ) );
    glDrawTransformFeedback = reinterpret_cast < PFNGLDRAWTRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glDrawTransformFeedback" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_transform_feedback3
    glDrawTransformFeedbackStream = reinterpret_cast < PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC > ( wglGetProcAddress( "glDrawTransformFeedbackStream" ) );
    glBeginQueryIndexed = reinterpret_cast < PFNGLBEGINQUERYINDEXEDPROC > ( wglGetProcAddress( "glBeginQueryIndexed" ) );
    glEndQueryIndexed = reinterpret_cast < PFNGLENDQUERYINDEXEDPROC > ( wglGetProcAddress( "glEndQueryIndexed" ) );
    glGetQueryIndexediv = reinterpret_cast < PFNGLGETQUERYINDEXEDIVPROC > ( wglGetProcAddress( "glGetQueryIndexediv" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 4.1
//////////////////////////////////////////////////////////////////////
bool OpenGL41()
{
    // sprawdzenie numeru wersji
    if( OpenGLVersion() < 41 )
        return false;


    // pobranie wskaünikÛw - rozszerzenie GL_ARB_ES2_compatibility
    glReleaseShaderCompiler = reinterpret_cast < PFNGLRELEASESHADERCOMPILERPROC > ( wglGetProcAddress( "glReleaseShaderCompiler" ) );
    glShaderBinary = reinterpret_cast < PFNGLSHADERBINARYPROC > ( wglGetProcAddress( "glShaderBinary" ) );
    glGetShaderPrecisionFormat = reinterpret_cast < PFNGLGETSHADERPRECISIONFORMATPROC > ( wglGetProcAddress( "glGetShaderPrecisionFormat" ) );
    glDepthRangef = reinterpret_cast < PFNGLDEPTHRANGEFPROC > ( wglGetProcAddress( "glDepthRangef" ) );
    glClearDepthf = reinterpret_cast < PFNGLCLEARDEPTHFPROC > ( wglGetProcAddress( "glClearDepthf" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_get_program_binary
    glGetProgramBinary = reinterpret_cast < PFNGLGETPROGRAMBINARYPROC > ( wglGetProcAddress( "glGetProgramBinary" ) );
    glProgramBinary = reinterpret_cast < PFNGLPROGRAMBINARYPROC > ( wglGetProcAddress( "glProgramBinary" ) );
    glProgramParameteri = reinterpret_cast < PFNGLPROGRAMPARAMETERIPROC > ( wglGetProcAddress( "glProgramParameteri" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_separate_shader_objects
    glUseProgramStages = reinterpret_cast < PFNGLUSEPROGRAMSTAGESPROC > ( wglGetProcAddress( "glUseProgramStages" ) );
    glActiveShaderProgram = reinterpret_cast < PFNGLACTIVESHADERPROGRAMPROC > ( wglGetProcAddress( "glActiveShaderProgram" ) );
    glCreateShaderProgramv = reinterpret_cast < PFNGLCREATESHADERPROGRAMVPROC > ( wglGetProcAddress( "glCreateShaderProgramv" ) );
    glBindProgramPipeline = reinterpret_cast < PFNGLBINDPROGRAMPIPELINEPROC > ( wglGetProcAddress( "glBindProgramPipeline" ) );
    glDeleteProgramPipelines = reinterpret_cast < PFNGLDELETEPROGRAMPIPELINESPROC > ( wglGetProcAddress( "glDeleteProgramPipelines" ) );
    glGenProgramPipelines = reinterpret_cast < PFNGLGENPROGRAMPIPELINESPROC > ( wglGetProcAddress( "glGenProgramPipelines" ) );
    glIsProgramPipeline = reinterpret_cast < PFNGLISPROGRAMPIPELINEPROC > ( wglGetProcAddress( "glIsProgramPipeline" ) );
    glGetProgramPipelineiv = reinterpret_cast < PFNGLGETPROGRAMPIPELINEIVPROC > ( wglGetProcAddress( "glGetProgramPipelineiv" ) );
    glProgramUniform1i = reinterpret_cast < PFNGLPROGRAMUNIFORM1IPROC > ( wglGetProcAddress( "glProgramUniform1i" ) );
    glProgramUniform1iv = reinterpret_cast < PFNGLPROGRAMUNIFORM1IVPROC > ( wglGetProcAddress( "glProgramUniform1iv" ) );
    glProgramUniform1f = reinterpret_cast < PFNGLPROGRAMUNIFORM1FPROC > ( wglGetProcAddress( "glProgramUniform1f" ) );
    glProgramUniform1fv = reinterpret_cast < PFNGLPROGRAMUNIFORM1FVPROC > ( wglGetProcAddress( "glProgramUniform1fv" ) );
    glProgramUniform1d = reinterpret_cast < PFNGLPROGRAMUNIFORM1DPROC > ( wglGetProcAddress( "glProgramUniform1d" ) );
    glProgramUniform1dv = reinterpret_cast < PFNGLPROGRAMUNIFORM1DVPROC > ( wglGetProcAddress( "glProgramUniform1dv" ) );
    glProgramUniform1ui = reinterpret_cast < PFNGLPROGRAMUNIFORM1UIPROC > ( wglGetProcAddress( "glProgramUniform1ui" ) );
    glProgramUniform1uiv = reinterpret_cast < PFNGLPROGRAMUNIFORM1UIVPROC > ( wglGetProcAddress( "glProgramUniform1uiv" ) );
    glProgramUniform2i = reinterpret_cast < PFNGLPROGRAMUNIFORM2IPROC > ( wglGetProcAddress( "glProgramUniform2i" ) );
    glProgramUniform2iv = reinterpret_cast < PFNGLPROGRAMUNIFORM2IVPROC > ( wglGetProcAddress( "glProgramUniform2iv" ) );
    glProgramUniform2f = reinterpret_cast < PFNGLPROGRAMUNIFORM2FPROC > ( wglGetProcAddress( "glProgramUniform2f" ) );
    glProgramUniform2fv = reinterpret_cast < PFNGLPROGRAMUNIFORM2FVPROC > ( wglGetProcAddress( "glProgramUniform2fv" ) );
    glProgramUniform2d = reinterpret_cast < PFNGLPROGRAMUNIFORM2DPROC > ( wglGetProcAddress( "glProgramUniform2d" ) );
    glProgramUniform2dv = reinterpret_cast < PFNGLPROGRAMUNIFORM2DVPROC > ( wglGetProcAddress( "glProgramUniform2dv" ) );
    glProgramUniform2ui = reinterpret_cast < PFNGLPROGRAMUNIFORM2UIPROC > ( wglGetProcAddress( "glProgramUniform2ui" ) );
    glProgramUniform2uiv = reinterpret_cast < PFNGLPROGRAMUNIFORM2UIVPROC > ( wglGetProcAddress( "glProgramUniform2uiv" ) );
    glProgramUniform3i = reinterpret_cast < PFNGLPROGRAMUNIFORM3IPROC > ( wglGetProcAddress( "glProgramUniform3i" ) );
    glProgramUniform3iv = reinterpret_cast < PFNGLPROGRAMUNIFORM3IVPROC > ( wglGetProcAddress( "glProgramUniform3iv" ) );
    glProgramUniform3f = reinterpret_cast < PFNGLPROGRAMUNIFORM3FPROC > ( wglGetProcAddress( "glProgramUniform3f" ) );
    glProgramUniform3fv = reinterpret_cast < PFNGLPROGRAMUNIFORM3FVPROC > ( wglGetProcAddress( "glProgramUniform3fv" ) );
    glProgramUniform3d = reinterpret_cast < PFNGLPROGRAMUNIFORM3DPROC > ( wglGetProcAddress( "glProgramUniform3d" ) );
    glProgramUniform3dv = reinterpret_cast < PFNGLPROGRAMUNIFORM3DVPROC > ( wglGetProcAddress( "glProgramUniform3dv" ) );
    glProgramUniform3ui = reinterpret_cast < PFNGLPROGRAMUNIFORM3UIPROC > ( wglGetProcAddress( "glProgramUniform3ui" ) );
    glProgramUniform3uiv = reinterpret_cast < PFNGLPROGRAMUNIFORM3UIVPROC > ( wglGetProcAddress( "glProgramUniform3uiv" ) );
    glProgramUniform4i = reinterpret_cast < PFNGLPROGRAMUNIFORM4IPROC > ( wglGetProcAddress( "glProgramUniform4i" ) );
    glProgramUniform4iv = reinterpret_cast < PFNGLPROGRAMUNIFORM4IVPROC > ( wglGetProcAddress( "glProgramUniform4iv" ) );
    glProgramUniform4f = reinterpret_cast < PFNGLPROGRAMUNIFORM4FPROC > ( wglGetProcAddress( "glProgramUniform4f" ) );
    glProgramUniform4fv = reinterpret_cast < PFNGLPROGRAMUNIFORM4FVPROC > ( wglGetProcAddress( "glProgramUniform4fv" ) );
    glProgramUniform4d = reinterpret_cast < PFNGLPROGRAMUNIFORM4DPROC > ( wglGetProcAddress( "glProgramUniform4d" ) );
    glProgramUniform4dv = reinterpret_cast < PFNGLPROGRAMUNIFORM4DVPROC > ( wglGetProcAddress( "glProgramUniform4dv" ) );
    glProgramUniform4ui = reinterpret_cast < PFNGLPROGRAMUNIFORM4UIPROC > ( wglGetProcAddress( "glProgramUniform4ui" ) );
    glProgramUniform4uiv = reinterpret_cast < PFNGLPROGRAMUNIFORM4UIVPROC > ( wglGetProcAddress( "glProgramUniform4uiv" ) );
    glProgramUniformMatrix2fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX2FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix2fv" ) );
    glProgramUniformMatrix3fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX3FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix3fv" ) );
    glProgramUniformMatrix4fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX4FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix4fv" ) );
    glProgramUniformMatrix2dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX2DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix2dv" ) );
    glProgramUniformMatrix3dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX3DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix3dv" ) );
    glProgramUniformMatrix4dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX4DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix4dv" ) );
    glProgramUniformMatrix2x3fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix2x3fv" ) );
    glProgramUniformMatrix3x2fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix3x2fv" ) );
    glProgramUniformMatrix2x4fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix2x4fv" ) );
    glProgramUniformMatrix4x2fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix4x2fv" ) );
    glProgramUniformMatrix3x4fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix3x4fv" ) );
    glProgramUniformMatrix4x3fv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC > ( wglGetProcAddress( "glProgramUniformMatrix4x3fv" ) );
    glProgramUniformMatrix2x3dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix2x3dv" ) );
    glProgramUniformMatrix3x2dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix3x2dv" ) );
    glProgramUniformMatrix2x4dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix2x4dv" ) );
    glProgramUniformMatrix4x2dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix4x2dv" ) );
    glProgramUniformMatrix3x4dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix3x4dv" ) );
    glProgramUniformMatrix4x3dv = reinterpret_cast < PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC > ( wglGetProcAddress( "glProgramUniformMatrix4x3dv" ) );
    glValidateProgramPipeline = reinterpret_cast < PFNGLVALIDATEPROGRAMPIPELINEPROC > ( wglGetProcAddress( "glValidateProgramPipeline" ) );
    glGetProgramPipelineInfoLog = reinterpret_cast < PFNGLGETPROGRAMPIPELINEINFOLOGPROC > ( wglGetProcAddress( "glGetProgramPipelineInfoLog" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_vertex_attrib_64bit
    glVertexAttribL1d = reinterpret_cast < PFNGLVERTEXATTRIBL1DPROC > ( wglGetProcAddress( "glVertexAttribL1d" ) );
    glVertexAttribL2d = reinterpret_cast < PFNGLVERTEXATTRIBL2DPROC > ( wglGetProcAddress( "glVertexAttribL2d" ) );
    glVertexAttribL3d = reinterpret_cast < PFNGLVERTEXATTRIBL3DPROC > ( wglGetProcAddress( "glVertexAttribL3d" ) );
    glVertexAttribL4d = reinterpret_cast < PFNGLVERTEXATTRIBL4DPROC > ( wglGetProcAddress( "glVertexAttribL4d" ) );
    glVertexAttribL1dv = reinterpret_cast < PFNGLVERTEXATTRIBL1DVPROC > ( wglGetProcAddress( "glVertexAttribL1dv" ) );
    glVertexAttribL2dv = reinterpret_cast < PFNGLVERTEXATTRIBL2DVPROC > ( wglGetProcAddress( "glVertexAttribL2dv" ) );
    glVertexAttribL3dv = reinterpret_cast < PFNGLVERTEXATTRIBL3DVPROC > ( wglGetProcAddress( "glVertexAttribL3dv" ) );
    glVertexAttribL4dv = reinterpret_cast < PFNGLVERTEXATTRIBL4DVPROC > ( wglGetProcAddress( "glVertexAttribL4dv" ) );
    glVertexAttribLPointer = reinterpret_cast < PFNGLVERTEXATTRIBLPOINTERPROC > ( wglGetProcAddress( "glVertexAttribLPointer" ) );
    glGetVertexAttribLdv = reinterpret_cast < PFNGLGETVERTEXATTRIBLDVPROC > ( wglGetProcAddress( "glGetVertexAttribLdv" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_viewport_array
    glViewportArrayv = reinterpret_cast < PFNGLVIEWPORTARRAYVPROC > ( wglGetProcAddress( "glViewportArrayv" ) );
    glViewportIndexedf = reinterpret_cast < PFNGLVIEWPORTINDEXEDFPROC > ( wglGetProcAddress( "glViewportIndexedf" ) );
    glViewportIndexedfv = reinterpret_cast < PFNGLVIEWPORTINDEXEDFVPROC > ( wglGetProcAddress( "glViewportIndexedfv" ) );
    glScissorArrayv = reinterpret_cast < PFNGLSCISSORARRAYVPROC > ( wglGetProcAddress( "glScissorArrayv" ) );
    glScissorIndexed = reinterpret_cast < PFNGLSCISSORINDEXEDPROC > ( wglGetProcAddress( "glScissorIndexed" ) );
    glScissorIndexedv = reinterpret_cast < PFNGLSCISSORINDEXEDVPROC > ( wglGetProcAddress( "glScissorIndexedv" ) );
    glDepthRangeArrayv = reinterpret_cast < PFNGLDEPTHRANGEARRAYVPROC > ( wglGetProcAddress( "glDepthRangeArrayv" ) );
    glDepthRangeIndexed = reinterpret_cast < PFNGLDEPTHRANGEINDEXEDPROC > ( wglGetProcAddress( "glDepthRangeIndexed" ) );
    glGetFloati_v = reinterpret_cast < PFNGLGETFLOATI_VPROC > ( wglGetProcAddress( "glGetFloati_v" ) );
    glGetDoublei_v = reinterpret_cast < PFNGLGETDOUBLEI_VPROC > ( wglGetProcAddress( "glGetDoublei_v" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// obs≥uga rozszerzenia GL_ARB_draw_buffers_blend
//////////////////////////////////////////////////////////////////////
PFNGLBLENDEQUATIONIARBPROC glBlendEquationiARB = NULL;
PFNGLBLENDEQUATIONSEPARATEIARBPROC glBlendEquationSeparateiARB = NULL;
PFNGLBLENDFUNCIARBPROC glBlendFunciARB = NULL;
PFNGLBLENDFUNCSEPARATEIARBPROC glBlendFuncSeparateiARB = NULL;

bool ARB_draw_buffers_blend()
{
    // sprawdzenie dostÍpnoúci rozszerzenia
    if ( !OpenGLExtension( "GL_ARB_draw_buffers_blend" ) )
        return false;

    // pobranie wskaünikÛw
    glBlendEquationiARB = reinterpret_cast < PFNGLBLENDEQUATIONIARBPROC > ( wglGetProcAddress( "glBlendEquationiARB" ) );
    glBlendEquationSeparateiARB = reinterpret_cast < PFNGLBLENDEQUATIONSEPARATEIARBPROC > ( wglGetProcAddress( "glBlendEquationSeparateiARB" ) );
    glBlendFunciARB = reinterpret_cast < PFNGLBLENDFUNCIARBPROC > ( wglGetProcAddress( "glBlendFunciARB" ) );
    glBlendFuncSeparateiARB = reinterpret_cast < PFNGLBLENDFUNCSEPARATEIPROC > ( wglGetProcAddress( "glBlendFuncSeparateiARB" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// obs≥uga rozszerzenia GL_ARB_sample_shading
//////////////////////////////////////////////////////////////////////
PFNGLMINSAMPLESHADINGARBPROC glMinSampleShadingARB = NULL;

bool ARB_sample_shading()
{
    // sprawdzenie dostÍpnoúci rozszerzenia
    if ( !OpenGLExtension( "GL_ARB_sample_shading" ) )
        return false;

    // pobranie wskaünikÛw
    glMinSampleShadingARB = reinterpret_cast < PFNGLMINSAMPLESHADINGARBPROC > ( wglGetProcAddress( "glMinSampleShadingARB" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// obs≥uga rozszerzenia GL_ARB_shading_language_include
//////////////////////////////////////////////////////////////////////
PFNGLNAMEDSTRINGARBPROC glNamedStringARB = NULL;
PFNGLDELETENAMEDSTRINGARBPROC glDeleteNamedStringARB = NULL;
PFNGLCOMPILESHADERINCLUDEARBPROC glCompileShaderIncludeARB = NULL;
PFNGLISNAMEDSTRINGARBPROC glIsNamedStringARB = NULL;
PFNGLGETNAMEDSTRINGARBPROC glGetNamedStringARB = NULL;
PFNGLGETNAMEDSTRINGIVARBPROC glGetNamedStringivARB = NULL;

bool ARB_shading_language_include()
{
    // sprawdzenie dostÍpnoúci rozszerzenia
    if ( !OpenGLExtension( "GL_ARB_shading_language_include" ) )
        return false;

    // pobranie wskaünikÛw
    glNamedStringARB = reinterpret_cast < PFNGLNAMEDSTRINGARBPROC > ( wglGetProcAddress( "glNamedStringARB" ) );
    glDeleteNamedStringARB = reinterpret_cast < PFNGLDELETENAMEDSTRINGARBPROC > ( wglGetProcAddress( "glDeleteNamedStringARB" ) );
    glCompileShaderIncludeARB = reinterpret_cast < PFNGLCOMPILESHADERINCLUDEARBPROC > ( wglGetProcAddress( "glCompileShaderIncludeARB" ) );
    glIsNamedStringARB = reinterpret_cast < PFNGLISNAMEDSTRINGARBPROC > ( wglGetProcAddress( "glIsNamedStringARB" ) );
    glGetNamedStringARB = reinterpret_cast < PFNGLGETNAMEDSTRINGARBPROC > ( wglGetProcAddress( "glGetNamedStringARB" ) );
    glGetNamedStringivARB = reinterpret_cast < PFNGLGETNAMEDSTRINGIVARBPROC > ( wglGetProcAddress( "glGetNamedStringivARB" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// obs≥uga rozszerzenia GL_ARB_cl_event
//////////////////////////////////////////////////////////////////////
PFNGLCREATESYNCFROMCLEVENTARBPROC glCreateSyncFromCLeventARB = NULL;

bool ARB_cl_event()
{
    // sprawdzenie dostÍpnoúci rozszerzenia
    if ( !OpenGLExtension( "GL_ARB_cl_event" ) )
        return false;

    // pobranie wskaünikÛw
    glCreateSyncFromCLeventARB = reinterpret_cast < PFNGLCREATESYNCFROMCLEVENTARBPROC > ( wglGetProcAddress( "glCreateSyncFromCLeventARB" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// obs≥uga rozszerzenia GL_ARB_debug_output
//////////////////////////////////////////////////////////////////////
PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARB = NULL;
PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARB = NULL;
PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARB = NULL;
PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARB = NULL;

bool ARB_debug_output()
{
    // sprawdzenie dostÍpnoúci rozszerzenia
    if ( !OpenGLExtension( "GL_ARB_debug_output" ) )
        return false;

    // pobranie wskaünikÛw
    glDebugMessageControlARB = reinterpret_cast < PFNGLDEBUGMESSAGECONTROLARBPROC > ( wglGetProcAddress( "glDebugMessageControlARB" ) );
    glDebugMessageInsertARB = reinterpret_cast < PFNGLDEBUGMESSAGEINSERTARBPROC > ( wglGetProcAddress( "glDebugMessageInsertARB" ) );
    glDebugMessageCallbackARB = reinterpret_cast < PFNGLDEBUGMESSAGECALLBACKARBPROC > ( wglGetProcAddress( "glDebugMessageCallbackARB" ) );
    glGetDebugMessageLogARB = reinterpret_cast < PFNGLGETDEBUGMESSAGELOGARBPROC > ( wglGetProcAddress( "glGetDebugMessageLogARB" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// obs≥uga rozszerzenia GL_ARB_robustness
//////////////////////////////////////////////////////////////////////
PFNGLGETGRAPHICSRESETSTATUSARBPROC glGetGraphicsResetStatusARB = NULL;
PFNGLGETNMAPDVARBPROC glGetnMapdvARB = NULL;
PFNGLGETNMAPFVARBPROC glGetnMapfvARB = NULL;
PFNGLGETNMAPIVARBPROC glGetnMapivARB = NULL;
PFNGLGETNPIXELMAPFVARBPROC glGetnPixelMapfvARB = NULL;
PFNGLGETNPIXELMAPUIVARBPROC glGetnPixelMapuivARB = NULL;
PFNGLGETNPIXELMAPUSVARBPROC glGetnPixelMapusvARB = NULL;
PFNGLGETNPOLYGONSTIPPLEARBPROC glGetnPolygonStippleARB = NULL;
PFNGLGETNCOLORTABLEARBPROC glGetnColorTableARB = NULL;
PFNGLGETNCONVOLUTIONFILTERARBPROC glGetnConvolutionFilterARB = NULL;
PFNGLGETNSEPARABLEFILTERARBPROC glGetnSeparableFilterARB = NULL;
PFNGLGETNHISTOGRAMARBPROC glGetnHistogramARB = NULL;
PFNGLGETNMINMAXARBPROC glGetnMinmaxARB = NULL;
PFNGLGETNTEXIMAGEARBPROC glGetnTexImageARB = NULL;
PFNGLREADNPIXELSARBPROC glReadnPixelsARB = NULL;
PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC glGetnCompressedTexImageARB = NULL;
PFNGLGETNUNIFORMFVARBPROC glGetnUniformfvARB = NULL;
PFNGLGETNUNIFORMIVARBPROC glGetnUniformivARB = NULL;
PFNGLGETNUNIFORMUIVARBPROC glGetnUniformuivARB = NULL;
PFNGLGETNUNIFORMDVARBPROC glGetnUniformdvARB = NULL;

bool ARB_robustness()
{
    // sprawdzenie dostÍpnoúci rozszerzenia
    if ( !OpenGLExtension( "GL_ARB_robustness" ) )
        return false;

    // pobranie wskaünikÛw
    glGetGraphicsResetStatusARB = reinterpret_cast < PFNGLGETGRAPHICSRESETSTATUSARBPROC > ( wglGetProcAddress( "glGetGraphicsResetStatusARB" ) );
    glGetnMapdvARB = reinterpret_cast < PFNGLGETNMAPDVARBPROC > ( wglGetProcAddress( "glGetnMapdvARB" ) );
    glGetnMapfvARB = reinterpret_cast < PFNGLGETNMAPFVARBPROC > ( wglGetProcAddress( "glGetnMapfvARB" ) );
    glGetnMapivARB = reinterpret_cast < PFNGLGETNMAPIVARBPROC > ( wglGetProcAddress( "glGetnMapivARB" ) );
    glGetnPixelMapfvARB = reinterpret_cast < PFNGLGETNPIXELMAPFVARBPROC > ( wglGetProcAddress( "glGetnPixelMapfvARB" ) );
    glGetnPixelMapuivARB = reinterpret_cast < PFNGLGETNPIXELMAPUIVARBPROC > ( wglGetProcAddress( "glGetnPixelMapuivARB" ) );
    glGetnPixelMapusvARB = reinterpret_cast < PFNGLGETNPIXELMAPUSVARBPROC > ( wglGetProcAddress( "glGetnPixelMapusvARB" ) );
    glGetnPolygonStippleARB = reinterpret_cast < PFNGLGETNPOLYGONSTIPPLEARBPROC > ( wglGetProcAddress( "glGetnPolygonStippleARB" ) );
    glGetnColorTableARB = reinterpret_cast < PFNGLGETNCOLORTABLEARBPROC > ( wglGetProcAddress( "glGetnColorTableARB" ) );
    glGetnConvolutionFilterARB = reinterpret_cast < PFNGLGETNCONVOLUTIONFILTERARBPROC > ( wglGetProcAddress( "glGetnConvolutionFilterARB" ) );
    glGetnSeparableFilterARB = reinterpret_cast < PFNGLGETNSEPARABLEFILTERARBPROC > ( wglGetProcAddress( "glGetnSeparableFilterARB" ) );
    glGetnHistogramARB = reinterpret_cast < PFNGLGETNHISTOGRAMARBPROC > ( wglGetProcAddress( "glGetnHistogramARB" ) );
    glGetnMinmaxARB = reinterpret_cast < PFNGLGETNMINMAXARBPROC > ( wglGetProcAddress( "glGetnMinmaxARB" ) );
    glGetnTexImageARB = reinterpret_cast < PFNGLGETNTEXIMAGEARBPROC > ( wglGetProcAddress( "glGetnTexImageARB" ) );
    glReadnPixelsARB = reinterpret_cast < PFNGLREADNPIXELSARBPROC > ( wglGetProcAddress( "glReadnPixelsARB" ) );
    glGetnCompressedTexImageARB = reinterpret_cast < PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC > ( wglGetProcAddress( "glGetnCompressedTexImageARB" ) );
    glGetnUniformfvARB = reinterpret_cast < PFNGLGETNUNIFORMFVARBPROC > ( wglGetProcAddress( "glGetnUniformfvARB" ) );
    glGetnUniformivARB = reinterpret_cast < PFNGLGETNUNIFORMIVARBPROC > ( wglGetProcAddress( "glGetnUniformivARB" ) );
    glGetnUniformuivARB = reinterpret_cast < PFNGLGETNUNIFORMUIVARBPROC > ( wglGetProcAddress( "glGetnUniformuivARB" ) );
    glGetnUniformdvARB = reinterpret_cast < PFNGLGETNUNIFORMDVARBPROC > ( wglGetProcAddress( "glGetnUniformdvARB" ) );

    // sukces
    return true;
}

#endif // WIN32

//////////////////////////////////////////////////////////////////////
// pobranie numeru wersji biblioteki OpenGL
// numer wersji pomnoøony przez 10
//////////////////////////////////////////////////////////////////////
int OpenGLVersion()
{
    int major = 0, minor = 0;
    glGetIntegerv( GL_MAJOR_VERSION, &major );
    glGetIntegerv( GL_MINOR_VERSION, &minor );
    return 10*major + minor;
}

//////////////////////////////////////////////////////////////////////
// sprawdzenie obs≥ugi rozszerzenia biblioteki OpenGL
// extName - nazwa sprawdzanego rozszerzenia OpenGL
//////////////////////////////////////////////////////////////////////
bool OpenGLExtension( const char *extName )
{
    GLint numExt;
    glGetIntegerv( GL_NUM_EXTENSIONS, &numExt );
    for( int i = 0; i < numExt; i++ )
        if( std::string( reinterpret_cast< const char* >( glGetStringi( GL_EXTENSIONS, i ) ) ) == std::string ( extName ) )
            return true;
    return false;
}

//////////////////////////////////////////////////////////////////////
// sprawdzenie wersji jÍzyka GLSL; numer wersji pomnoøony przez 100
//////////////////////////////////////////////////////////////////////
int GLSLVersion()
{
    // pobranie numery wersji GLSL
    std::stringstream version( std::stringstream::in | std::stringstream::out );
    version << reinterpret_cast< const char* >( glGetString( GL_SHADING_LANGUAGE_VERSION ) );
    if( glGetError() != GL_NO_ERROR ) return 0;

    // numer wersji pomnoøony przez 100
    int major = 0, minor = 0;
    char dot;
    version >> major;
    if( version.fail() )return 0;
    version >> dot;
    if( version.fail() || dot != '.' ) return 0;
    version >> minor;
    if( version.fail() ) return 0;
    return 100*major + minor;
}

