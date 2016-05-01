
package cse222_hw8;

public class Edge {

  
  // Data Fields
  /** The source vertix */
  private int source;
  /** The destination vertix */
  private int dest;
  /** The weight */
  private double weight;

  
  /** The puzzle*/
 /* private ArrayList<Integer> puzzle;*/
  // Constructor
  /** Construct an Edge with a source of from
      and a destination of to. Set the weight
      to 1.0.
      @param from - The source vertix
      @param to - The destination vertix
   */
  public Edge(int source, int dest) {
    this.source = source;
    this.dest = dest;
  /*  puzzle=null;*/
    weight = 1.0;
  }

  /** Construct a weighted edge with a source
      of from and a destination of to. Set the
      weight to w.
      @param from - The source vertix
      @param to - The destination vertix
      @param w - The weight
   */
  public Edge(int source, int dest, double w) {
    this.source = source;
    this.dest = dest;
   /* puzzle=null;*/
    weight = w;
  }
    /** Construct a weighted edge with a source
      of from and a destination of to. Set the
      weight to w.
      @param from - The source vertix
      @param to - The destination vertix
     * @param puzz - The puzzle
   */
/*  public Edge(int source, int dest, ArrayList<Integer> puzz) {
    this.source = source;
    this.dest = dest;
    weight = 1.0;
   /* puzzle=new ArrayList<Integer>();*/
    /*puzzle.addAll(puzz);*/
  //}

  // Methods
  /** Get the source
      @return The value of source
   */
  public int getSource() {
    return source;
  }

  /** Get the destination
      @return The value of dest
   */
  public int getDest() {
    return dest;
  }

  /** Set the destination
     * @param dest value 
      @return The value of dest
   */
  public void setDest(int dest) {
     this.dest=dest;
  }
  
  
  /** Get the weight
      @return the value of weight
   */
  public double getWeight() {
    return weight;
  }
  /** Get the puzzle
      @return the value of weight
   *//*
  public ArrayList<Integer> getPuzzle() {
    return puzzle;
  }*/
  /** Return a String representation of the edge
      @return A String representation of the edge
   */
  public String toString() {
    StringBuffer sb = new StringBuffer("[(");
    sb.append(Integer.toString(source));
    sb.append(", ");
    sb.append(Integer.toString(dest));
    sb.append("): ");
    sb.append(Double.toString(weight));
    sb.append("]");
    return sb.toString();
  }

  /** Return true if two edges are equal. Edges
      are equal if the source and destination
      are equal. Weight is not conidered.
      @param obj The object to compare to
      @return true if the edges have the same source
      and destination
   */
  public boolean equals(Object obj) {
    if (obj instanceof Edge) {
      Edge edge = (Edge) obj;
      return (source == edge.source
              && dest == edge.dest);
    }
    else {
      return false;
    }
  }

  /** Return a hash code for an edge.  The hash
      code is the source shifted left 16 bits
      exclusive or with the dest
      @return a hash code for an edge
   */
  public int hashCode() {
    return (source << 16) ^ dest;
  }
  
}