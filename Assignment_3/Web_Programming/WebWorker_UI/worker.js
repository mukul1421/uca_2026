fetch("https://gorest.in/public/v2/users")
.then(function(response) {

    if (!response.ok) {
        throw new Error("Unable to fetch data");
    }

    return response.json();
})
.then(function(users) {

    console.log(users);
    if (users.length == 0) {
        postMessage("No users returned from API.");
        return;
    }

    for (var i = 0; i < users.length; i++) {

        if (users[i].status == "active") {
            postMessage(users[i].name + " - Active");
        }
        else {
            postMessage(users[i].name + " - Inactive");
        }

    }

})
.catch(function(error) {
    postMessage(error.message);
});
