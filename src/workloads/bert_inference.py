# FP16
from transformers import BertTokenizer, BertModel
import torch

# BERT 모델 및 토크나이저 로드
tokenizer = BertTokenizer.from_pretrained("bert-base-uncased")
model = BertModel.from_pretrained("bert-base-uncased").cuda()

# 입력 데이터 준비
text = "Hugging Face is the best!"
inputs = tokenizer(text, return_tensors="pt")
inputs = {key: value.cuda() for key, value in inputs.items()}

# FP16 추론
with torch.no_grad():
    with torch.cuda.amp.autocast():  # FP16 연산 활성화
        outputs = model(**inputs)

# 결과 출력
print(outputs.last_hidden_state)

# output_file = "model_structure.txt"
# with open(output_file, "w") as f:
#     for name, layer in model.named_modules():
#         f.write(f"{name}: {layer}\n")