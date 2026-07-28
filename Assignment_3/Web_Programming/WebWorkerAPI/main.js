const worker = new Worker("worker.js");

worker.onmessage = function(event) {
    console.log(event.data);
};

worker.onerror = function() {
    console.log("Worker Error");
};
