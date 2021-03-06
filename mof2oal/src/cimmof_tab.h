typedef union {
	CCIMClass*				cimclass;
	CCIMMethod*				cimmethod;
	CCIMProperty*			cimproperty;
	CCIMParameter*			cimparameter;
	CCIMReference*			cimreference;
	string*					strval;
	int						val;
} YYSTYPE;
#define	TOK_ALIAS_IDENTIFIER	258
#define	TOK_ANY	259
#define	TOK_AS	260
#define	TOK_ASSOCIATION	261
#define	TOK_BINARY_VALUE	262
#define	TOK_CHAR_VALUE	263
#define	TOK_CLASS	264
#define	TOK_COLON	265
#define	TOK_COMMA	266
#define	TOK_DISABLEOVERRIDE	267
#define	TOK_DQUOTE	268
#define	TOK_DT_BOOL	269
#define	TOK_DT_CHAR16	270
#define	TOK_DT_CHAR8	271
#define	TOK_DT_DATETIME	272
#define	TOK_DT_REAL32	273
#define	TOK_DT_REAL64	274
#define	TOK_DT_SINT16	275
#define	TOK_DT_SINT32	276
#define	TOK_DT_SINT64	277
#define	TOK_DT_SINT8	278
#define	TOK_DT_STR	279
#define	TOK_DT_UINT16	280
#define	TOK_DT_UINT32	281
#define	TOK_DT_UINT64	282
#define	TOK_DT_UINT8	283
#define	TOK_ENABLEOVERRIDE	284
#define	TOK_END_OF_FILE	285
#define	TOK_EQUAL	286
#define	TOK_FALSE	287
#define	TOK_FLAVOR	288
#define	TOK_HEX_VALUE	289
#define	TOK_INCLUDE	290
#define	TOK_INDICATION	291
#define	TOK_INSTANCE	292
#define	TOK_LEFTCURLYBRACE	293
#define	TOK_LEFTPAREN	294
#define	TOK_LEFTSQUAREBRACKET	295
#define	TOK_METHOD	296
#define	TOK_NULL_VALUE	297
#define	TOK_OCTAL_VALUE	298
#define	TOK_OF	299
#define	TOK_PARAMETER	300
#define	TOK_PERIOD	301
#define	TOK_POSITIVE_DECIMAL_VALUE	302
#define	TOK_PRAGMA	303
#define	TOK_PROPERTY	304
#define	TOK_QUALIFIER	305
#define	TOK_REAL_VALUE	306
#define	TOK_REF	307
#define	TOK_REFERENCE	308
#define	TOK_RESTRICTED	309
#define	TOK_RIGHTCURLYBRACE	310
#define	TOK_RIGHTPAREN	311
#define	TOK_RIGHTSQUAREBRACKET	312
#define	TOK_SCHEMA	313
#define	TOK_SCOPE	314
#define	TOK_SEMICOLON	315
#define	TOK_SIGNED_DECIMAL_VALUE	316
#define	TOK_SIMPLE_IDENTIFIER	317
#define	TOK_STRING_VALUE	318
#define	TOK_TOSUBCLASS	319
#define	TOK_TRANSLATABLE	320
#define	TOK_TRUE	321
#define	TOK_UNEXPECTED_CHAR	322


extern YYSTYPE yylval;
