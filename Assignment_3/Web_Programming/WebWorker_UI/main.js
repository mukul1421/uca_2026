var worker = new Worker("worker.js");

worker.onmessage = function(event) {
    document.getElementById("users").innerHTML += event.data + "<br>";
};

worker.onerror = function() {
    document.getElementById("users").innerHTML = "Worker Error";
};
