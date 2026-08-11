import java.util.PriorityQueue;

class Village {

	int population;
	int clinics;

	Village(int population){
		this.population = population;
		this.clinics = 1;
	}

	double getLoad(){
		return (double) population/clinics;
	}

}

public class KClinics {

	public static double minLoad(int[] population, int k){
	
		PriorityQueue<Village> maxHeap = new PriorityQueue<>(
				(a,b)-> Double.compare(b.getLoad(), a.getLoad()));

		for(int p: population){
			maxHeap.offer( new Village(p) );
		}

		for(int i=0; i<k-population.length; i++){
		
			Village village = maxHeap.poll();
			village.clinics++;

			maxHeap.offer(village);
		
		}

		return maxHeap.peek().getLoad();

	}

	public static void main(String[] args){
	
		int[] population = {200, 20, 50};
		int k = 5;

		double minimumLoad = minLoad(population, k);

		System.out.printf("Minimum Load: %.2f%n", minimumLoad);

	}

}
