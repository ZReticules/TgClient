@module TgClient
	include "FASM_OOP\String.inc"
	include "FASM_OOP\JSONNode.inc"

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

		make 				dm this	; (this, botKey:LPWSTRZ)
		call 				dm this	; (this, methodType:LPWSTRZ, methodName:LPWSTRZ, body:PSTR, bodySize:INT)
		update 				dm this	; (this)
		send 				dm this
		reply				dm this	; (this, message:P_JSONNode, response:PSTR, respLen:INT, parseMode:)
		onMessage			dm this
		onEdit				dm this
		onCommand			dm this
		onUnknownCommand 	dm this
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
