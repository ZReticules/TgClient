@module TgClient
	include "FASM_OOP\String.inc"
	include "FASM_OOP\JSONNode.inc"
	include "FASM_OOP\cstdio.inc"
	
	include "FASM_OOP\COM\IServerXMLHTTPRequest.inc"

	struct TgClient
		__updates 	rq 1
		__httpObj	P_IServerXMLHTTPRequest ?
		__ini		rptr 1
		__onMsg 	rptr 1
		__onEdit	rptr 1
		__onUnkCmd	rptr 1
		__comDict	SimpleDict
		__url 		WString
		apiKey 		rptr 1
		fpLog 		rptr 1

		make 				dm this	; (this, botKey:PWSTRZ)
		call 				dm this	; (this, methodType:PWSTRZ, methodName:PWSTRZ, body:PSTR, bodySize:INT)
		update 				dm this	; (this)
		send 				dm this	; (this, chatId:QWORD, message:PSTR, msgLen:INT, parseMode:(PWSTR or NULL))
		reply				dm this	; (this, message:P_JSONNode, response:PSTR, respLen:INT, parseMode:(PWSTR or NULL))
		getMe 				dm this	; (this)
		onMessage			dm this	; (this, callback)
									; callback(bot:P_MyTgClient, msg:P_JSONNode)
		onEdit				dm this
		onUnknownCommand 	dm this
		onCommand			dm this	; (this, command:PSTR, callback)
									; callback(bot:P_MyTgClient, msg:P_JSONNode, cmdData:P_TgClient.CommandData)
		start 				dm this	; (this)
		getCallResult		dm this ; (this, pResult:P_TgClient.SendingResult)
		unmake 				dm this
	ends

	struct TgClient.CommandData
		reserved 	rptr 1
		pText		rptr 1
		textLen		rd 1
		commandLen	rd 1
	ends

	struct TgClient.CallResult
		json JSONNode
		variant VARIANT
		bytes rptr 1

		unmake dm this
	ends

	include "TgClient.fasm"
@endm
