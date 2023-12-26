      // Sort the items in insertion sort 
      for (int i = 1; i < size; i++) {
        Item key = items[i];
        int j = i - 1;

        while (j >= 0 && (static_cast<double>(items[j].value) / items[j].weight) < (static_cast<double>(key.value) / key.weight)) {
            items[j + 1] = items[j];
            j = j - 1;
        }
        items[j + 1] = key;
    }