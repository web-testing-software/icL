listen "ws://127.0.0.1:8989" : (@type = "error", @message : string) {
    Log.out("error: ", @message);
}
