from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
import pandas as pd
from DecisionTree import DecisionTree


col_names = ["Name", "Year", "Miles", "Price"]
data = pd.read_csv("carvana.csv", skiprows=1, header=None, names=col_names)

X = data.iloc[:, :-1].values
y = data.iloc[:, -1].values

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=1234
)

clf = DecisionTree(max_depth=3)
clf.fit(X_train, y_train)
predictions = clf.predict(X_test)


def accuracy(y_test, y_pred):
    return np.sum(y_test == y_pred) / len(y_test)


acc = accuracy(y_test, predictions)
print(acc)
