now @listen = listen "ws://127.0.0.1:8989";
now @hander = @listen.handle(@type = "error", @message : string);

@handler.setup icL{
    Log.out("error: ", @message);
};
