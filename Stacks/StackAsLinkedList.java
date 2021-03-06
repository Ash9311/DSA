public class StackAsLinkedList{
    
    StackNode root;

    static class StackNode{
        int data;
        StackNode next;

        StackNode(int data){
            this.data = data;
        }
    }

    public boolean isEmpty(){
        if(root==null){
            return true;
        }
        else{
            return false;
        }
    }

    public void push(int data){
        StackNode newNode = new StackNode(data);
        if(root==null){
            root = newNode;
        }
        else{
            StackNode temp = root;
            root = newNode;
            newNode.next = temp;
        }
        System.out.println(data+" is pushed to the stack");
    }

    public int pop(){
        int popped = Integer.MIN_VALUE;
        if(root==null){
            System.out.println("The stack is empty");
        }
        else{
            popped = root.data;
            root = root.next;
        }
        return popped;
    }

    public int peek(){
        if(root==null){
            System.out.println("The stack is empty");
            return Integer.MIN_VALUE;
        }
        return root.data;
    }

    public static void main(String[] args){
        StackAsLinkedList sll = new StackAsLinkedList();
        sll.push(9);
        sll.push(4);
        sll.push(8);
        System.out.println(sll.pop()+" is popped from stack");
        System.out.println(sll.peek()+" is the top element");
    }
}