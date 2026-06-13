import os
import cv2
import numpy as np
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D
from tensorflow.keras.layers import Flatten, Dense, Dropout
from tensorflow.keras.utils import to_categorical

# ==========================================
# PARAMETERS
# ==========================================

IMG_SIZE = 128
DATASET_PATH = "/content/kagglecatsanddogs_5340.zip"

categories = ["cats", "dogs"]

X = []
y = []

# ==========================================
# LOAD AND PREPROCESS IMAGES
# ==========================================

print("Loading Images...")

for label, category in enumerate(categories):

    folder_path = os.path.join(DATASET_PATH, category)

    for image_name in os.listdir(folder_path):

        image_path = os.path.join(folder_path, image_name)

        try:

            # ----------------------------------
            # Read Image
            # ----------------------------------
            img = cv2.imread(image_path)

            # ----------------------------------
            # Resize
            # ----------------------------------
            img = cv2.resize(img, (IMG_SIZE, IMG_SIZE))

            # ----------------------------------
            # Convert BGR -> Grayscale
            # ----------------------------------
            gray = cv2.cvtColor(
                img,
                cv2.COLOR_BGR2GRAY
            )

            # ----------------------------------
            # Gaussian Blur
            # ----------------------------------
            blur = cv2.GaussianBlur(
                gray,
                (5,5),
                0
            )

            # ----------------------------------
            # Adaptive Threshold
            # ----------------------------------
            thresh = cv2.adaptiveThreshold(
                blur,
                255,
                cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                cv2.THRESH_BINARY,
                11,
                2
            )

            # ----------------------------------
            # Normalize
            # ----------------------------------
            thresh = thresh / 255.0

            X.append(thresh)

            y.append(label)

        except Exception as e:

            print("Error:", image_path)
            print(e)

# ==========================================
# CONVERT TO NUMPY ARRAYS
# ==========================================

X = np.array(X)
y = np.array(y)

print("Dataset Loaded")
print("X Shape =", X.shape)
print("Y Shape =", y.shape)

# ==========================================
# RESHAPE FOR CNN
# ==========================================

X = X.reshape(
    -1,
    IMG_SIZE,
    IMG_SIZE,
    1
)

# ==========================================
# ONE HOT ENCODING
# ==========================================

y = to_categorical(y, num_classes=2)

# ==========================================
# TRAIN TEST SPLIT
# ==========================================

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.20,
    random_state=42
)

print("Training Images:", len(X_train))
print("Testing Images :", len(X_test))

# ==========================================
# BUILD CNN MODEL
# ==========================================

model = Sequential()

# Layer 1
model.add(
    Conv2D(
        32,
        (3,3),
        activation='relu',
        input_shape=(IMG_SIZE, IMG_SIZE, 1)
    )
)

model.add(MaxPooling2D((2,2)))

# Layer 2
model.add(
    Conv2D(
        64,
        (3,3),
        activation='relu'
    )
)

model.add(MaxPooling2D((2,2)))

# Layer 3
model.add(
    Conv2D(
        128,
        (3,3),
        activation='relu'
    )
)

model.add(MaxPooling2D((2,2)))

# Flatten
model.add(Flatten())

# Dense Layer
model.add(Dense(128, activation='relu'))

# Dropout
model.add(Dropout(0.5))

# Output Layer
model.add(Dense(2, activation='softmax'))

# ==========================================
# COMPILE MODEL
# ==========================================

model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy']
)

# ==========================================
# MODEL SUMMARY
# ==========================================

model.summary()

# ==========================================
# TRAIN MODEL
# ==========================================

history = model.fit(
    X_train,
    y_train,
    epochs=10,
    batch_size=32,
    validation_data=(X_test, y_test)
)

# ==========================================
# EVALUATE MODEL
# ==========================================

loss, accuracy = model.evaluate(
    X_test,
    y_test
)

print("\nAccuracy =", accuracy * 100)

# ==========================================
# SAVE MODEL
# ==========================================

model.save("cat_dog_cnn_threshold.h5")

print("Model Saved Successfully")

# ==========================================
# PLOT ACCURACY
# ==========================================

plt.figure(figsize=(8,5))

plt.plot(
    history.history['accuracy'],
    label='Training Accuracy'
)

plt.plot(
    history.history['val_accuracy'],
    label='Validation Accuracy'
)

plt.title("CNN Accuracy")

plt.xlabel("Epoch")

plt.ylabel("Accuracy")

plt.legend()

plt.show()
















import cv2
import numpy as np
from tensorflow.keras.models import load_model

IMG_SIZE = 128

model = load_model(
    "cat_dog_cnn_threshold.h5"
)

img = cv2.imread("test.jpg")

img = cv2.resize(
    img,
    (IMG_SIZE, IMG_SIZE)
)

gray = cv2.cvtColor(
    img,
    cv2.COLOR_BGR2GRAY
)

blur = cv2.GaussianBlur(
    gray,
    (5,5),
    0
)

thresh = cv2.adaptiveThreshold(
    blur,
    255,
    cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
    cv2.THRESH_BINARY,
    11,
    2
)

thresh = thresh / 255.0

thresh = thresh.reshape(
    1,
    IMG_SIZE,
    IMG_SIZE,
    1
)

prediction = model.predict(thresh)

predicted_class = np.argmax(prediction)

if predicted_class == 0:
    print("CAT")
else:
    print("DOG")