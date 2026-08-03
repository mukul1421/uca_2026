const fields = [
    "First Name",
    "Last Name",
    "Email"
];

function generateForm() {
    return fields.map(field => `
        <label>${field}</label><br>
        <input type="text"><br><br>
    `).join("");
}

document.getElementById("myForm").innerHTML = generateForm();
