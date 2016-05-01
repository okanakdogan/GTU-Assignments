
package cse222_hw8;
import java.util.*;

public interface Graph {

  // Accessor Methods
  /** Return the number of vertices.
      @return The number of vertices
   */
  int getNumV();

  /** Determine whether this is a directed graph.
      @return true if this is a directed graph
   */
  boolean isDirected();

  /** Insert a new edge into the graph.
      @param edge The new edge
   */
  void insert(Edge edge);

  /** Determine whether an edge exists.
      @param source The source vertex
      @param dest The destination vertex
      @return true if there is an edge from source to dest
   */
  boolean isEdge(int source, int dest);

  /** Get the edge between two vertices.
      @param source The source vertex
      @param dest The destination vertex
      @return The Edge between these two vertices
              or an Edge with a weight of
              Double.POSITIVE_INFINITY if there is no edge
   */
  Edge getEdge(int source, int dest);

  /** Return an iterator to the edges connected
      to a given vertex.
      @param source The source vertex
      @return An Iterator<Edge> to the vertices
              connected to source
   */
  Iterator < Edge > edgeIterator(int source);

}
