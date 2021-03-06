#ifndef REPRUNEH
#define REPRUNEH

/** \ingroup CoreAPI DecisionTree
*/

/** \file

\brief Peforms reduced error pruning on a decision tree.

Takes a decision tree and a collection of examples and prunes every
portion of the tree that does not contribute to an increase of
accuracy on the data set. This requires a single pass over the prune
set, and then on order of one pass over the tree for each node that is
pruned.

REPrune uses the growing data fields of the decision tree, so it will
overwrite anything that you may have there. If you want to trying
pruning a tree and then continue growing it you should make a clone of
the tree and pass the clone to this interface so that the origional
will remain untouched.

\wish More pruning methods, and more sophisticated REPruning (for
example, all the leaves to prune could be selected in a single pass
over the tree).

*/



#include "vfml.h"

/** \brief Get the prune set from the in-memory list. */
void REPruneBatch(DecisionTreePtr dt, VoidAListPtr examples);


/** \brief Get the prune set from the file

Do not use more than pruneMax of the examples from the file for
pruning; setting pruneMax to 0 means 'no max' (and uses all examples
from the file for pruning).
*/
void REPruneBatchFile(DecisionTreePtr dt, FILE *exampleIn, long pruneMax);

#endif
