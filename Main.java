import java.util.Scanner;

class Main {
    public static void disp(int[] arr){
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }
    
    public static int[] bubbleSort(int[] arr){
        int[] ret = arr.clone();
        for(int i = 0; i < ret.length; i++){
            for(int j = 0; j < ret.length - 1; j++){
                if(ret[j] > ret[j + 1]){
                    int t = ret[j];
                    ret[j] = ret[j + 1];
                    ret[j + 1] = t;
                }
            }
        }
        return(ret);
    }
    
    public static int[] selectionSort(int[] arr){
        int[] ret = arr.clone();
        for(int i = 0; i < ret.length; i++){
            int min = i;
            for(int j = i + 1; j < ret.length; j++){
                if(ret[j] < ret[min]){
                    min = j;
                }
            }
            int t = ret[i];
            ret[i] = ret[min];
            ret[min] = t;
        }
        return(ret);
    }
    
    public static int[] insertionSort(int[] arr){
        int[] ret = arr.clone();
        for(int i = 1; i < ret.length; i++){
            int key = ret[i];
            int j = i  - 1;
            
            while(j >= 0 && ret[j] > key){
                ret[j + 1] = ret[j];
                j--;
            }
            ret[j + 1] = key;
        }
        return(ret);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Enter number of elements-");
        int l = scan.nextInt();
        int[] arr = new int[l];
        for(int i = 0; i < l; i++){
            int t = scan.nextInt();
            arr[i] = t;
        }
        
        disp(arr);
        int[] bubble = bubbleSort(arr);
        disp(bubble);
        int[] selection = selectionSort(arr);
        disp(selection);
        int[] insertion = insertionSort(arr);
        disp(insertion);
        
    }
}
