import java.util.PriorityQueue;

public class MedianFinder{

	private PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
    	private PriorityQueue<Integer> minHeap = new PriorityQueue<>();

	public void insert(int num) {
	
		if(maxHeap.isEmpty() || num <= maxHeap.peek()) {
			maxHeap.offer(num);
		}
		else {
			minHeap.offer(num);
		}

		if(maxHeap.size() > minHeap.size()+1) {
			minHeap.offer(maxHeap.poll());
		}
		else if(minHeap.size() > maxHeap.size()){
			maxHeap.offer(minHeap.poll());
		}

	}

	public float getMedian() {

	        if (maxHeap.isEmpty()) {
            		return 0.0f;
        	}
       		if (maxHeap.size() > minHeap.size()) {
         		return maxHeap.peek();
		}

		return (maxHeap.peek() + minHeap.peek()) / 2.0f;
       	}

	public static void main(String[] args){
	
		MedianFinder mf = new MedianFinder();

        	mf.insert(5);
        	System.out.println(mf.getMedian()); 

        	mf.insert(15);
        	System.out.println(mf.getMedian());  

        	mf.insert(1);
        	System.out.println(mf.getMedian()); 

        	mf.insert(3);
        	System.out.println(mf.getMedian());

        	mf.insert(8);
	        System.out.println(mf.getMedian());

	}

}
