from numpy import array, reshape
from sklearn import tree

# Creates data table
features = [[140, 1], [130, 1], [150, 0], [170, 0]]
labels = [0, 0, 1, 1]

# Calls sklearn with previous data
clf = tree.DecisionTreeClassifier()
clf = clf.fit(features, labels)

# Data to test
temp = [160, 0]
temp = array(temp).reshape((1, -1))

# Show result on screen
print clf.predict(temp)
