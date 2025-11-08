@module TgClient
	include "FASM_OOP\String.inc"
	include "FASM_OOP\JSONNode.inc"
	include "FASM_OOP\cstdio.inc"
	
	include "FASM_OOP\COM\IServerXMLHTTPRequest.inc"

	struct TgClient
		updates 	rq 1
		apiKey 		rptr 1
		__httpObj	P_IServerXMLHTTPRequest ?
		__ini		rptr 1
		__onMsg 	rptr 1
		__onEdit	rptr 1
		__onUnkCmd	rptr 1
		__comDict	SimpleDict
		url 		WString
		fpLog 		rptr 1

		make 				dm this	; (this, botKey:PWSTRZ)
		call 				dm this	; (this, methodType:PWSTRZ, methodName:PWSTRZ, body:PSTR, bodySize:INT)
		update 				dm this	; (this)
		send 				dm this	; (this, message:PSTR, msgLen:INT, parseMode:(PWSTR or NULL))
		reply				dm this	; (this, message:P_JSONNode, response:PSTR, respLen:INT, parseMode:)
		onMessage			dm this	; (this, callback)
									; callback(bot:P_MyTgClient, msg:P_JSONNode)
		onEdit				dm this
		onUnknownCommand 	dm this
		onCommand			dm this	; (this, command:PSTR, callback)
									; callback()
		start 				dm this
		; process 			dm this
		unmake 				dm this
	ends

	struct TgClient.CommandData
		reserved 	rptr 1
		pText		rptr 1
		textLen		rd 1
		commandLen	rd 1
	ends

	include "TgClient.fasm"
@endm
