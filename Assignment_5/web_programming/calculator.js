function* calc(initialValue) {

	if( typeof initialValue !== "number" || Number.isNaN(initialValue) ) {
		throw new Error("Invalid initial Value");
	}

	let result = initialValue;

	while(true) {

		const input = yield(result);

		if( !input || 
		    typeof input.operation !== "string" ||
		    typeof input.value !== "number" ||
		    Number.isNaN(initialValue) ) {

			console.log("Invalid input");
           		continue;

		}

		const {operation, value} = input;

		switch(operation) {

			case "add":
	        	        result += value;
        	        	break;

	                case "subtract":
                		result -= value;
                		break;

            		case "multiply":
                		result *= value;
                		break;

            		case "divide":
                		if (value === 0) {
                    			console.log("Cannot divide by zero");
                    			continue;
                		}
                		result /= value;
                		break;

            		default:
                		console.log("Invalid operation");
                		continue;

		}
		
		console.log(result);


	}

}

const calculator = calc(50);

console.log(calculator.next());

calculator.next({ operation: "add", value: 30 });

calculator.next({ operation: "multiply", value: 2 });

calculator.next({ operation: "add", value: "30" });

calculator.next({ operation: "multiply", value: 0 });
