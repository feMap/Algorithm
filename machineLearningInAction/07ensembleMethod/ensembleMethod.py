#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Mon Apr 16 18:17:42 2018

@author: femap
"""
import random

def loadDataSet(filename):
    dataset = []
    with open(filename, 'r') as fr:
        for line in fr.readlines():
            if not line:
                continue
            lineArr = []
            for feature in line.split(','):
                str_f = feature.strip()
                if str_f.isdigit():
                    lineArr.append(float(str_f))
                else:
                    lineArr.append(str_f)
            dataset.append(lineArr)
    return dataset

def cross_validation_split(dataset, n_folds):
    dataset_split = list()
    dataset_copy = list(dataset)
    fold_size = len(dataset) / n_folds

    for i in range(n_folds):
        fold = list()
        while len(fold) < fold_size:
            index = random.randrange(len(dataset_copy))
            fold.append(dataset_copy.pop(index))
        dataset_split.append(fold)
        
    return dataset_split

def subsample(dataset, ratio):
    sample = list()
    n_sample = round(len(dataset) * ratio)
    while len(sample) < n_sample:
        index = random.randrange(len(dataset))
        sample.append(dataset[index])
    return sample

def get_split(dataset, n_features):
    class_values = list(set(row[-1] for row in dataset))
    b_index, b_value, b_score, b_groups = 999, 999, 999, None
    features = list()
    while len(features) < n_features:
        index = randrange(len(dataset[0]) - 1)

def build_tree(train, max_depth, min_size, n_features):
    root = get_split(train, n_features)
    
    split(root, max_depth, min_size, n_features, 1)
    
    return root

def random_forest(train, test, max_depth, min_size, sample_size, n_trees, n_features):
    trees = list()
    for i in range(n_trees):
        sample = subsample(train, sample_size)
        tree = build_tree(sample, max_depth, min_size, n_features)
        trees.append(tree)
        
    predictions = [bagging_predict(trees, row) for row in test]
    
    return predictions

def accuracy_metric(actual, predicted):
    correct = 0
    for i in range(len(actual)):
        if actual[i] == predicted[i]:
            correct += 1
    return correct / float(len(actual)) * 100.0

def evaluate_algorithm(dataset, algorithm, n_folds, *args):
    folds = cross_validation_split(dataset, n_folds)
    scores = list()
    for fold in folds:
        train_set = list(folds)
        train_set.remove(fold)
        
        train_set = sum(train_set, [])
        test_set = list()
        
        for row in fold:
            row_copy = list(row)
            row_copy[-1] = None
            test_set.append(row_copy)
        
        predicted = algorithm(train_set, test_set, *args)
        actual = [row[-1] for row in fold ]
        
        accuary = accuracy_metric(actual, predicted)
        scores.append(accuary)
    return scores
        
if __name__ == "__main__":
    dataset = loadDataSet('sonar-all-data.txt')
    
    n_folds = 5
    max_depth = 20
    min_size = 1
    sample_size = 1.0
    # n_features = int(len(dataset[0] - 1))
    n_features = 15
    for n_trees in [1, 10, 20, 30, 40, 50]:
        scores = evaluate_algorithm(dataset, random_forest, n_folds, max_depth, min_size, n_trees, n_features)
        random.seed(1)
        print "random = ", random()
        print "Trees: %d" % n_trees
        print "Scores: %s" % scores
        print "Mean Accuracy: %.3f%%" %(sum(scores) / float(len(scores)))